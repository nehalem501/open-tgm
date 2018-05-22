/* Stack.cpp */

#include <stdint.h>
#include <string.h>
#include <Piece.h>
#include <Shapes.h>
#include <Utils.h>
#include <Mode.h>
#include <core/Player.h>
#include <core/Stack.h>

Core::Stack::Stack() : m_height(22), m_width(10) {
}

void Core::Stack::init(int pos_x, int pos_y, int width, int height) {
    // Stack size
    m_width = width;
    m_height = height;

    #ifdef DEBUG
    print("width: %d  height: %d\n", m_width, m_height);
    #endif

    // Position in tiles
    m_pos_x = pos_x;
    m_pos_y = pos_y;

    // Init Stack
    memset(m_field, 0, MAX_WIDTH * MAX_HEIGHT * sizeof(tiles_t));
    memset(m_field, 0, MAX_WIDTH * MAX_HEIGHT * sizeof(tiles_t));

    // Init filled lines storage
    memset(m_filled_lines, -1, FILLED_LINES_NB * sizeof(int));
}

void Core::Stack::start_game(Mode *mode) {
    // TODO
    init(m_pos_x, m_pos_y, mode->width(), mode->height());
}

int Core::Stack::get_ghost_y(Piece *piece) {
    bool can_go_down = true;
    int pos_y = piece->pos_y();
    while(can_go_down) {
        pos_y = pos_y + 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (PIECES[piece->type()][piece->orientation()][j][i] > 0) {
                    int x = piece->pos_x() - 2 + i;
                    int y = pos_y - 1 + j;
                    if (x < 0 || x >= m_width || y >= m_height) {
                        can_go_down = false;
                    } else if (m_field[x + y * m_width] > 0) {
                        can_go_down = false;
                    }
                }
            }
        }
    }

    // TODO multiplayer

    return (pos_y - 1);
}

bool Core::Stack::check_new_pos(Piece *piece, int new_x, int new_y,
                                   int new_rotation) {
    int pos_x = piece->pos_x() + new_x;
    int pos_y = piece->pos_y() + new_y;
    int rotation = modulo(piece->orientation() + new_rotation, 4);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type()][rotation][j][i] > 0) {
                int x = pos_x - 2 + i;
                int y = pos_y - 1 + j;
                if (x < 0 || x >= m_width || y >= m_height) {
                    return false;
                }
                else if (m_field[x + y * m_width] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

void Core::Stack::shift_line(unsigned int line) {
    //std::cout << "height: " << m_height << std::endl;
    if ((int) line > m_height - 1)
        return;

    // Shift lines above this one
    memmove(m_field + m_width, m_field, line * m_width * sizeof(tiles_t));
    memmove(m_outline + m_width, m_outline, line * m_width * sizeof(tiles_t));

    // Update outline after shifting line
    update_outline(line);
    update_outline(line + 1);
}

void Core::Stack::shift_lines() {
    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        if (m_filled_lines[i] != -1) {
            //std::cout << m_filled_lines[i] << ", ";
            shift_line(m_filled_lines[i]);
            m_filled_lines[i] = -1;
        }
    }
    //std::cout << std::endl;
}

bool Core::Stack::check_bravo() {
    unsigned int size = m_width * m_height;
    for (unsigned int i = 0; i < size; i++) {
        if (m_field[i])
            return false;
    }

    return true;
}

bool Core::Stack::check_line(unsigned int line) {
    for (unsigned int i = line * m_width; i < (line + 1) * m_width; i++) {
        if (m_field[i] == 0)
            return false;
    }

    return true;
}

bool Core::Stack::check_lines(Core::Player *player) {
    int pos_y = player->m_piece.pos_y();

    int lines_to_clear = 0;
    int bravo = check_bravo() ? 4 : 1;

    for (int row_nb = pos_y - 1; row_nb <= pos_y + 2 && row_nb < m_height; row_nb++) {
        if (check_line(row_nb)) {
            int row = row_nb * m_width;

            // Clear line
            memset(m_field + row, 0, m_width * sizeof(tiles_t));
            memset(m_outline + row, 0, m_width * sizeof(tiles_t));

            // Update outline of surrounding lines
            update_outline(row_nb - 1);
            update_outline(row_nb + 1);

            // Add line coords to remove line later
            m_filled_lines[lines_to_clear] = row_nb; // TODO doubles
            //std::cout << row_nb << ", ";

            // Activate particles for line clear
            m_part[lines_to_clear].set_emitter(this, row_nb);
            m_part[lines_to_clear].init();

            // Increment line count
            lines_to_clear++;
        }
    }
    //std::cout << std::endl;

    if (lines_to_clear > 0) {
        // TODO we need to compute the 'real' next level value
        // for update score, so before using change_level
        player->update_score(lines_to_clear, bravo);
        //player->startClear();
        player->change_level(lines_to_clear, true);
        //std::cout << "to clear\n";
        return true;
    }

    player->set_combo(1);
    //std::cout << "nothing\n";
    //player->startARE();
    return false;
}

void Core::Stack::remove_line(unsigned int line) {
    if ((int) line < m_height) {
        memset(m_field + line * m_width, 0, m_width * sizeof(tiles_t));
        update_outline(line - 1);
        update_outline(line);
        update_outline(line + 1);

    }
}

void Core::Stack::update_outline(unsigned int unsigned_line) {
    int line = (int) unsigned_line;
    if (line < m_height) {
        for (int i = 0; i < m_width; i++) {
            m_outline[i + m_width * line] = 0;
            if (m_field[i + m_width * line]) {
                if (i > 0) // Left
                    if (!m_field[i - 1 + m_width * line])
                        m_outline[i + m_width * line] |= OUTLINE_LEFT;

                if (line > 0) // Top
                    if (!m_field[i + m_width * (line - 1)])
                        m_outline[i + m_width * line] |= OUTLINE_UP;

                if (line < m_height - 1) // Bottom
                    if (!m_field[i + m_width * (line + 1)])
                        m_outline[i + m_width * line] |= OUTLINE_DOWN;

                if (i < m_width - 1) // Right
                    if (!m_field[i + 1 + m_width * line])
                        m_outline[i + m_width * line] |= OUTLINE_RIGHT;
            }
        }
    }
}

void Core::Stack::remove_grey_blocks(Piece *piece) {
    int pos_x = piece->pos_x() - 2;
    int pos_y = piece->pos_y() - 1;
    int limit_x = pos_x + SIZE;
    int limit_y = pos_y + SIZE;

    if (pos_x < 0)
        pos_x = 0;
    if (pos_y < 0)
        pos_y = 0;
    if (limit_x > m_width)
        limit_x = m_width;
    if (limit_y > m_height)
        limit_y = m_height;

    for (int i = pos_y; i < limit_y; i++) {
        for (int j = pos_x; j < limit_x; j++) {
            if (m_field[j + m_width * i] == 8) {
                m_field[j + m_width * i] = piece->type() + 1;
            }
        }
    }
}
