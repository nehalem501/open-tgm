/* Stack.cpp */

#include <string.h>
#include <TargetTypes.h>
#include <Piece.h>
#include <Shapes.h>
#include <Utils.h>
#include <Mode.h>
#include <Player.h>
#include <Debug.h>
#include <Stack.h>

Stack::Stack(Position &parent) :
        m_parent(parent),
        m_implementation(*this)
{
}

void Stack::init(Position& parent, const uint8_t width, const uint8_t height) {
    //printd(DebugCategory::STACK, "width: ", m_width, ", height: ", m_height);

    // Parent position in tiles
    m_parent = parent;

    // Init Stack
    //memset(m_field, 0, m_width * m_height * sizeof(Block));
    m_field.reset(width, height);

    // Init filled lines storage
    //memset(m_filled_lines, -1, FILLED_LINES_NB * sizeof(int));

    // Initialize particles
    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        //m_particles[i];
    }
}

void Stack::start_game(const Mode mode) {
    // TODO
    init(m_parent, mode.width(), mode.height());
}

void Stack::shift_line(unsigned int /*line*/) {
    //std::cout << "height: " << m_height << std::endl;
    /*if (line > m_height - 1)
        return;

    // Shift lines above this one
    memmove(m_field + m_width, m_field, line * m_width * sizeof(Block));

    // Update outline after shifting line
    update_outline(line);
    update_outline(line + 1);

    m_implementation.update_outline();
    m_implementation.update_field();*/
}

void Stack::shift_lines() {
    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        /*if (m_filled_lines[i] != -1) {
            //std::cout << m_filled_lines[i] << ", ";
            shift_line(m_filled_lines[i]);
            m_filled_lines[i] = -1;
        }*/
    }
    //std::cout << std::endl;
}

bool Stack::check_bravo() {
    /*unsigned int size = m_width * m_height;
    for (unsigned int i = 0; i < size; i++) {
        if (m_field[i].filled())
            return false;
    }*/

    return true;
}

bool Stack::check_lines(Player& /*player*/) {
    /*int pos_y = player.piece().coordinates().y;

    int lines_to_clear = 0;

    for (int row_nb = pos_y - 1; row_nb <= pos_y + 2 && row_nb < (int) m_height; row_nb++) {
        if (check_line(row_nb)) {
            int row = row_nb * m_width;

            // Clear line
            memset(m_field + row, 0, m_width * sizeof(Block));

            // Update outline of surrounding lines
            update_outline(row_nb - 1);
            update_outline(row_nb + 1);

            // Add line coords to remove line later
            //m_filled_lines[lines_to_clear] = row_nb; // TODO doubles
            //std::cout << row_nb << ", ";

            // Activate particles for line clear
            //m_particles[lines_to_clear].set_emitter(m_parent, row_nb);

            // Increment line count
            lines_to_clear++;
        }
    }
    //std::cout << std::endl;

    m_implementation.update_field();
    m_implementation.update_outline();

    if (lines_to_clear > 0) {
        // TODO we need to compute the 'real' next level value
        // for update score, so before using change_level
        player.update_score(lines_to_clear, check_bravo());
        //player->startClear();
        player.change_level(lines_to_clear, true);
        //std::cout << "to clear\n";
        return true;
    }

    player.set_combo(1);
    //std::cout << "nothing\n";
    //player->startARE();
*/
    return false;
}

void Stack::remove_line(int /*line*/) {
    /*if (line > 0 && line < (int) m_height) {
        memset(m_field + line * m_width, 0, m_width * sizeof(Block));
        //memset(m_outline + line * m_width, 0, m_width * sizeof(tiles_t));
        update_outline(line - 1);
        update_outline(line + 1);

        m_implementation.update_outline();
        m_implementation.update_field();
    }*/
}

void Stack::update_outline(size_t /*line*/) {
    /*if (line < m_height) {
        for (size_t i = 0; i < m_width; i++) {
            //m_outline[i + m_width * line] = 0;
            if (block(i, line).filled()) {
                if (i > 0) // Left
                    if (block(i - 1, line).empty()) {
                        block_mut(i, line).add_outline(Outline::Left);
                    }

                if (line > 0) // Top
                    if (block(i, line - 1).empty()) {
                        block_mut(i, line).add_outline(Outline::Top);
                    }

                if (line < m_height - 1) // Bottom
                    if (block(i, line + 1).empty()) {
                        block_mut(i, line).add_outline(Outline::Bottom);
                    }

                if (i < m_width - 1) // Right
                    if (block(i + 1, line).empty()) {
                        block_mut(i, line).add_outline(Outline::Right);
                    }
            }
        }
    }*/
}

void Stack::remove_grey_blocks(const Piece& /*piece*/) {
    // TODO change coordinates if lines were cleared
    /*int pos_x = piece.coordinates().x - 2;
    int pos_y = piece.coordinates().y - 1;
    int limit_x = pos_x + 4;
    int limit_y = pos_y + 4;

    if (pos_x < 0)
        pos_x = 0;
    if (pos_y < 0)
        pos_y = 0;
    if (limit_x > (int)m_width)
        limit_x = m_width;
    if (limit_y > (int)m_height)
        limit_y = m_height;

    for (int i = pos_y; i < limit_y; i++) {
        for (int j = pos_x; j < limit_x; j++) {
            block_mut(j, i).reset_blink();
        }
    }*/
}

void Stack::draw() const {
    // TODO
    m_implementation.render();
}

