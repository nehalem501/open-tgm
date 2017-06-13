/* BaseStack.cpp */

#include <stdint.h>
#include <cstring>
#include <Piece.h>
#include <Shapes.h>
#include <Utils.h>
#include <Mode.h>
#include <common/BasePlayer.h>
#include <common/BaseStack.h>

BaseStack::BaseStack() : m_height(22), m_width(10) {
}

void BaseStack::init(int pos_x, int pos_y, int width, int height) {
    // Stack size
    m_width = width;
    m_height = height;

    // Line break particles
    m_active_particles = 0;

    // Position in tiles
    m_pos_x = pos_x;
    m_pos_y = pos_y;

    // Init Stack
    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        m_stack[i] = 0;
        m_outline[i] = 0;
    }

    for (int j = 0; j < FILLED_LINES_NB; j++) {
        m_filled_lines[j] = -1;
    }
}

void BaseStack::startGame(Mode *mode) {
    // TODO
    init(m_pos_x, m_pos_y, mode->size_x, mode->size_y);
}

int8_t BaseStack::getGhostY(Piece *piece) {
    bool canGoDown = true;
    int8_t pos_x = piece->pos_x;
    int8_t pos_y = piece->pos_y;
    while(canGoDown) {
        pos_y = pos_y + 1;
        int8_t x;
        int8_t y;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (PIECES[piece->type][piece->orientation][j][i] > 0) {
                    x = pos_x - 2 + i;
                    y = pos_y - 1 + j;
                    if (x < 0 || x >= m_width || y >= m_height) {
                        canGoDown = false;
                    }
                    else if (m_stack[x + y * m_width] > 0) {
                        canGoDown = false;
                    }
                }
            }
        }
    }

    // TODO multiplayer

    return (pos_y - 1);
}

bool BaseStack::checkMove(Piece *piece, int x, int y) {
    int pos_x = piece->pos_x + x;
    int pos_y = piece->pos_y + y;
    int tmp_x;
    int tmp_y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][piece->orientation][j][i] > 0) {
                tmp_x = pos_x - 2 + i;
                tmp_y = pos_y - 1 + j;
                if (tmp_x < 0 || tmp_x >= m_width || tmp_y >= m_height) {
                    return false;
                }
                else if (m_stack[tmp_x + m_width * tmp_y] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

bool BaseStack::checkLeftRotation(Piece *piece) {
    int pos_x = piece->pos_x;
    int pos_y = piece->pos_y;
    int rotation = modulo(piece->orientation + 1, 4);
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][rotation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;
                if (x < 0 || x >= m_width || y >= m_height) {
                    return false;
                }
                else if (m_stack[x + y * m_width] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

bool BaseStack::checkLeftKickRotation(Piece *piece, int x_offset, int y_offset) {
    int pos_x = piece->pos_x + x_offset;
    int pos_y = piece->pos_y + y_offset;
    int rotation = modulo(piece->orientation + 1, 4);
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][rotation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;
                if (x < 0 || x >= m_width || y >= m_height) {
                    return false;
                }
                else if (m_stack[x + y * m_width] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

bool BaseStack::checkRightRotation(Piece *piece) {
    int pos_x = piece->pos_x;
    int pos_y = piece->pos_y;
    int rotation = modulo(piece->orientation - 1, 4);
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][rotation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;
                if (x < 0 || x >= m_width || y >= m_height) {
                    return false;
                }
                else if (m_stack[x + y * m_width] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

bool BaseStack::checkRightKickRotation(Piece *piece, int x_offset, int y_offset) {
    int pos_x = piece->pos_x + x_offset;
    int pos_y = piece->pos_y + y_offset;
    int rotation = modulo(piece->orientation - 1, 4);
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][rotation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;
                if (x < 0 || x >= m_width || y >= m_height) {
                    return false;
                }
                else if (m_stack[x + y * m_width] > 0) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}
#include<iostream>

void BaseStack::shiftLine(int8_t line) {
    //std::cout << "height: " << m_height << std::endl;
    if (line > m_height - 1)
        return;

    // Shift lines above this one
    memmove(m_stack + m_width, m_stack, line * m_width);
    memmove(m_outline + m_width, m_outline, line * m_width);

    // Update outline after shifting line
    updateOutline(line);
    updateOutline(line + 1);
}

void BaseStack::shiftLines() {
    int8_t nb_lines = 0;

    while (m_filled_lines[nb_lines] != -1 && nb_lines < FILLED_LINES_NB) {
        /*if (m_filled_lines[nb_lines] != -1) {
            break;
        }*/
        nb_lines++;
        //std::cout << "for: nb_line: " << (int) nb_lines << std::endl;
    }
    #warning "shiftLines not finished"
    for (int i = 0; i < FILLED_LINES_NB; i++) {
        //std::cout << "filled[" << (int) i << "]: " << (int) m_filled_lines[i] << std::endl;
    }

    //std::cout << "nb_line: " << (int) nb_lines << std::endl;
    switch (nb_lines) { //TODO
        case 1:
            //std::cout << "line: " << (int) m_filled_lines[0] << std::endl;
            shiftLine(m_filled_lines[0]);
            break;

        case 2:
            //std::cout << "line: " << (int) m_filled_lines[0] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[1] << std::endl;
            shiftLine(m_filled_lines[0]);
            shiftLine(m_filled_lines[1]);
            break;

        case 3:
            //std::cout << "line: " << (int) m_filled_lines[0] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[1] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[2] << std::endl;
            shiftLine(m_filled_lines[0]);
            shiftLine(m_filled_lines[1]);
            shiftLine(m_filled_lines[2]);
            break;

        case 4:
            //std::cout << "line: " << (int) m_filled_lines[0] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[1] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[2] << std::endl;
            //std::cout << "line: " << (int) m_filled_lines[3] << std::endl;
            shiftLine(m_filled_lines[0]);
            shiftLine(m_filled_lines[1]);
            shiftLine(m_filled_lines[2]);
            shiftLine(m_filled_lines[3]);
            break;
    }

    m_filled_lines[0] = -1;
    m_filled_lines[1] = -1;
    m_filled_lines[2] = -1;
    m_filled_lines[3] = -1;
}

void BaseStack::checkLines(BasePlayer *player) {
    int size = m_width * m_height;

    int8_t lines_to_clear = 0;
    int8_t bravo = 4;
    int8_t line_nb = 0;

    int row_nb = 0;
    for (int row = 0; row < size; row += m_width, row_nb++) {
        bool line = true;

        // Check line
        for (int i = row; i < row + m_width; i++) {
            if (m_stack[i] == 0) {
                line = false; // Line is not completely filled
                //break; // TODO
                goto end_for;
            } else {
                bravo = 1; // Sorry, no bravo this time :(
            }
        }
end_for:
        // The line will be cleared
        if (line) {
            //std::cout << "row: "<< row << std::endl;
            //std::cout << "rownb: "<< row_nb << std::endl;

            // Add line coords to remove line later
            m_filled_lines[lines_to_clear] = row_nb; // TODO doubles

            // Increment line count
            lines_to_clear++;

            // Clear line
            memset(m_stack + row, 0, m_width);
            memset(m_outline + row, 0, m_width);

            // Update outline of surrounding lines
            updateOutline(row_nb - 1);
            updateOutline(row_nb + 1);

            // Activate particles for line clear
            switch (lines_to_clear) {
                case 1:
                    m_part0.setEmitter(0, row_nb);
                    m_part0.init();
                    break;

                case 2:
                    m_part1.setEmitter(0, row_nb);
                    m_part1.init();
                    break;

                case 3:
                    m_part2.setEmitter(0, row_nb);
                    m_part2.init();
                    break;

                case 4:
                    m_part3.setEmitter(0, row_nb);
                    m_part3.init();
                    break;
            }

        }

        line_nb++;
    }

    if (lines_to_clear > 0) {
        player->updateScore(lines_to_clear, bravo);
        //sort(m_filled_lines, FILLED_LINES_NB);

        player->startClear();
        player->changeLevel(lines_to_clear, true);
    } else {
        player->setCombo(1);
        player->startARE();
    }
}

void BaseStack::updateOutline(int8_t line) {
    if (line >= 0 && line < m_height) {
        for (int i = 0; i < m_width; i++) {
            m_outline[i + m_width * line] = 0;
            if (m_stack[i + m_width * line]) {
                if (i > 0) // Left
                    if (!m_stack[i - 1 + m_width * line])
                        m_outline[i + m_width * line] |= OUTLINE_LEFT;

                if (line > 0) // Top
                    if (!m_stack[i + m_width * (line - 1)])
                        m_outline[i + m_width * line] |= OUTLINE_UP;

                if (line < m_height - 1) // Bottom
                    if (!m_stack[i + m_width * (line + 1)])
                        m_outline[i + m_width * line] |= OUTLINE_DOWN;

                if (i < m_width - 1) // Right
                    if (!m_stack[i + 1 + m_width * line])
                        m_outline[i + m_width * line] |= OUTLINE_RIGHT;
            }
        }
    }
}

void BaseStack::removeGreyBlocks(Piece *piece) {
    int pos_x = piece->pos_x;
    int pos_y = piece->pos_y;
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[piece->type][piece->orientation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;

                if (m_stack[x + m_width * y]) {
                    m_stack[x + m_width * y] = piece->type + 1;
                }
            }
        }
    }
}
