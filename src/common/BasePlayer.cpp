/* BasePlayer.cpp */

#include <cstdlib>
#include <stdint.h>
#include <cmath>
#include <ctime>
#include <Global.h>
#include <Input.h>
#include <Shapes.h>
#include <Mode.h>
#include <Utils.h>
#include <Stack.h>
#include <common/BasePlayer.h>

/* Used at program startup */
void BasePlayer::init(Stack *stack) {
    m_stack = stack;
    score_display.initGraphics();
    level_display.initGraphics();
    section_display.initGraphics();
}

/* Init the field and all the other stuff */
void BasePlayer::init(Stack *stack, Mode *mode) {
    m_stack = stack;
    m_current_mode = mode;

    m_score = 0;
    m_level = 0;

    m_active_time = 0;
    m_gravity = 0;
    m_gravity_counter = 0;
    m_section = mode->getSection(0);

    m_already_dropped = false;
    m_lock_color_delay = 0;

    m_drawPiece = true;
    m_drawGhost = true;
    m_startDASleft = false;
    m_startDASright = false;

    m_piece.type = 0;
    m_piece.orientation = 0;
    m_piece.pos_x = 0;
    m_piece.pos_y = 0;

    m_ghost_y = 0;
    m_piece_old_y = 0;
    m_next = 0;

    m_startARE = false;
    m_startClear = false;
    m_startLock = false;

    m_rotLeft = true;
    m_rotRight = true;

    m_are = 0;
    m_line_are = 0;
    m_lock = 0;
    m_combo = 0;

    m_sonic = 0;
    m_soft = 0;
    m_clear = 0;

    m_DASleft = 0;
    m_DASright = 0;

    score_display.init(mode->score_pos.x, mode->score_pos.y);
    level_display.init(mode->level_pos.x, mode->level_pos.y);
    section_display.init(mode->level_target_pos.x, mode->level_target_pos.y);
    section_display.update(m_section);
    section_display.updateGraphics(stack);

    // TODO
/* In TGM1, the history begins filled with 4 Z pieces.
 * From TGM2 onward, the history begins with a Z,Z,S,S sequence.
 * However, as the first piece of the game overwrites the first Z
 * rather than pushing off the last S,
 * this is effectively a Z,S,S,Z or Z,S,Z,S sequence. */
    m_history[0] = Shape::Z;
    m_history[1] = Shape::Z;
    m_history[2] = Shape::S;
    m_history[3] = Shape::S;

    // TODO special rules for first piece
    changeLevel(0, false);
    nextPiece();
}

/*  */
void BasePlayer::nextPiece() {
    m_piece.orientation = 0;
    m_piece.type = m_next;

    m_active_time = 0;

    char r;

    // TODO change number off tries depending on mode (TGM1/TAP)
    for (int i = 0; i < 5; ++i) {
        r = tgm_random(&rand_seed) % 7;

        if (r != m_history[0] && r != m_history[1] &&
            r != m_history[2] && r != m_history[3]) {
            break;
        }

        r = tgm_random(&rand_seed) % 7;
    }

    m_history[3] = m_history[2];
    m_history[2] = m_history[1];
    m_history[1] = m_history[0];
    m_history[0] = r;

    m_next = r;

    m_piece.pos_x = 5;
    m_piece.pos_y = 2;

    m_piece_old_y = m_piece.pos_y;

    m_ghost_y = m_stack->getGhostY(&m_piece);
}

/* Update for 1 frame */
void BasePlayer::update() {
    m_piece_old_y = m_piece.pos_y;

    if (m_lock_color_delay != 0) {
        m_lock_color_delay--;
        if (m_lock_color_delay == 0) {
            //Piece old(m_history[], 0, m_piece_old_y
            m_stack->removeGreyBlocks(&m_piece); // TODO
        }
    }

    // Check ARE Delay
    if (checkARE()) {
        nextPiece();

        m_sonic = 0;
        m_soft = 0;

        //m_values.gravity_counter = 0;
        changeLevel(1, false);
        m_drawPiece = true;

        // Hide ghost piece after level 100
        if (m_level > 100) {
            m_drawGhost = false;
        } else {
            m_drawGhost = true;
        }

        m_already_dropped = false;

        if (canIRSLeft()) {
            m_piece.orientation = modulo(m_piece.orientation + 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }

        if (canIRSRight()) {
            m_piece.orientation = modulo(m_piece.orientation - 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }

        /*if(!checkGameOver()) {
            //cout << "GAME OVER !!!" << endl;
            lockPiece();
            stack->removeGreyBlocks(m_piece); // TODO
            m_values.gameover = true;
        }*/
    }

    m_active_time++;

    //updateInput();
    //TODO Left Priority
    // Rotate Left
    if (input.rotateLeft()) {
        if (canRotateLeft()) {
            canRotateLeftStart();
            //cout << "rotation left" << endl;
            rotateLeft();
        }
    } else {
        canRotateLeftStop();
    }

    // Rotate Right
    if (input.rotateRight()) {
        if (canRotateRight()) {
            canRotateRightStart();
            //cout << "rotation right" << endl;
            rotateRight();
        }
    } else {
        canRotateRightStop();
    }

    // TODO check if bug with ARE
    // Down
    if (input.down()) {
        if (notInARE()) {
            move(0, 1);
            m_soft++;
            if (!m_stack->checkMove(&m_piece, 0, 1)) {
                if (!m_already_dropped) {
                    lockPiece();
                    resetLock();
                    //game.startARE = true;
                    m_stack->checkLines(this);
                }
            }
        }
    }

    // Left
    if (input.left()) {
        if (m_startDASleft) {
            if (checkDASleft()) {
                if (notInARE()) {
                    move(-1, 0);
                    m_ghost_y = m_stack->getGhostY(&m_piece);
                    //cout << "left" << endl;
                }
            }
        } else {
            m_startDASleft = true;
            if (notInARE()) {
                move(-1, 0);
                m_ghost_y = m_stack->getGhostY(&m_piece);
                //cout << "left" << endl;
            }
        }
    } else {
        if (m_startDASleft) {
            m_startDASleft = false;
            m_DASleft = 0;
        }
    }

    // Right
    if (input.right()) {
        if (m_startDASright) {
            if (checkDASright()) {
                if (notInARE()) {
                    move(1, 0);
                    m_ghost_y = m_stack->getGhostY(&m_piece);
                    //cout << "right" << endl;
                }
            }
        } else {
            m_startDASright = true;
            if (notInARE()) {
                move(1, 0);
                m_ghost_y = m_stack->getGhostY(&m_piece);
                //cout << "right" << endl;
            }
        }
    } else {
        if (m_startDASright) {
            m_startDASright = false;
            m_DASright = 0;
        }
    }

    // TODO check if bug with ARE
    // Fast drop
    if (input.up()) {
        if (m_current_mode->sonic_drop) {
            moveDrop();
            //std::cout << "drop" << std::endl;
        }
    }

    // Gravity
    unsigned int number_down = gravity();
    if (number_down) { //TODO optimize
        for (unsigned int i = 0; i < number_down; i++) {
            move(0, 1);
        }
    }

    // Start counting lock delay
    if (!m_stack->checkMove(&m_piece, 0, 1)) {
        if (notInARE()) {
            if (m_piece_old_y != m_piece.pos_y) {
                resetLock();
            }

            if (notInClear()) {
                startLock();
                //cout << "lock: " << game.lock << endl;
            }
        }
    } else {
        if (hasLockStarted()) {
            if (m_piece_old_y != m_piece.pos_y) {
                resetLock();
            }
        } else {
            resetLock();
        }
    }

    // Lock Delay
    if (checkLock()) {
        lockPiece();
        resetLock();
        m_stack->checkLines(this);
    }

    // Clear Delay
    if (checkClear()) {
        m_stack->shiftLines();
        //m_stack->resetCompletedLines();
        startARE();
    }
}

/* Move piece */
void BasePlayer::move(int x, int y) {
    if(m_stack->checkMove(&m_piece, x, y)) {
        m_piece.pos_x += x;
        m_piece.pos_y += y;
        m_ghost_y = m_stack->getGhostY(&m_piece);
    }
}

/* Sonic drop */
void BasePlayer::moveDrop() {
    if(m_stack->checkMove(&m_piece, 0, 1)) {
        m_sonic = m_ghost_y - m_piece.pos_y;
        m_piece.pos_y = m_ghost_y;
    }
}

/* Rotate piece to the left if possible */
void BasePlayer::rotateLeft() {
    // Check if center column occupied (T piece case)
    if (m_piece.type == Shape::T) {
        int x = m_piece.pos_x - 1;
        if (x >= 0 || x < m_stack->m_width) {
            int y = m_piece.pos_y - 1;
            if (y < m_stack->m_height && y >= 0) {
                if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                    return;
                }
            }
        }
    }

    // Check basic rotation
    if (m_stack->checkLeftRotation(&m_piece)) {
        m_piece.orientation = modulo(m_piece.orientation + 1, 4);
        m_ghost_y = m_stack->getGhostY(&m_piece);
    }

    // No wallkicks for I and O pieces
    else if (m_piece.type != Shape::I && m_piece.type != Shape::O) {

        // Check if center column occupied (J and L pieces case)
        if (m_piece.type == Shape::J || m_piece.type == Shape::L) {
            int x = 0;
            int y = 0;

            // check if J wallkick is still possible
            if (m_piece.type == Shape::J) {
                x = m_piece.pos_x;
                y = m_piece.pos_y - 1;
                if (x >= 0 || x < m_stack->m_width) {
                    if (y < m_stack->m_height && y >= 0) {
                        if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                            // Check wallkick right
                            if (m_stack->checkLeftKickRotation(&m_piece, 1, 0)) {
                                m_piece.pos_x++;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            // Check wallkick left
                            if (m_stack->checkLeftKickRotation(&m_piece, -1, 0)) {
                                m_piece.pos_x--;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            return;
                        }
                    }
                }
            }

            // check if L wallkick is still possible
            if (m_piece.type == Shape::L) {
                x = m_piece.pos_x - 2;
                y = m_piece.pos_y - 1;
                if (x >= 0 || x < m_stack->m_width) {
                    if (y < m_stack->m_height && y >= 0) {
                        if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                            // Check wallkick right
                            if (m_stack->checkLeftKickRotation(&m_piece, 1, 0)) {
                                m_piece.pos_x++;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            // Check wallkick left
                            if (m_stack->checkLeftKickRotation(&m_piece, -1, 0)) {
                                m_piece.pos_x--;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            return;
                        }
                    }
                }
            }

            x = m_piece.pos_x - 1;

            if (x >= 0 || x < m_stack->m_width) {
                y = m_piece.pos_y - 1;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_piece.pos_y;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_piece.pos_y + 1;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }
            }
        }

        // Check wallkick right
        if (m_stack->checkLeftKickRotation(&m_piece, 1, 0)) {
            m_piece.pos_x++;
            m_piece.orientation = modulo(m_piece.orientation + 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }

        // Check wallkick left
        else if (m_stack->checkLeftKickRotation(&m_piece, -1, 0)) {
            m_piece.pos_x--;
            m_piece.orientation = modulo(m_piece.orientation + 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }
    }
}

/* Rotate piece to the right if possible */
void BasePlayer::rotateRight() {
    // Center column disables rotation with T piece
    if (m_piece.type == Shape::T) {
        int x = m_piece.pos_x - 1;
        if (x >= 0 || x < m_stack->m_width) {
            int y = m_piece.pos_y - 1;
            if (y < m_stack->m_height && y >= 0) {
                if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                    return;
                }
            }
        }
    }

    // Check basic rotation
    if (m_stack->checkRightRotation(&m_piece)) {
        m_piece.orientation = modulo(m_piece.orientation - 1, 4);
        m_ghost_y = m_stack->getGhostY(&m_piece);
    }

    // No wallkicks for I and O pieces
    else if (m_piece.type != Shape::I && m_piece.type != Shape::O) {

        // Check if center column occupied (J and L pieces case)
        if (m_piece.type == Shape::J || m_piece.type == Shape::L) {
            int x = 0;
            int y = 0;

            // check if J wallkick is still possible
            if (m_piece.type == Shape::J) {
                x = m_piece.pos_x;
                y = m_piece.pos_y - 1;
                if (x >= 0 || x < m_stack->m_width) {
                    if (y < m_stack->m_height && y >= 0) {
                        if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                            // Check wallkick right
                            if (m_stack->checkLeftKickRotation(&m_piece, 1, 0)) {
                                m_piece.pos_x++;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            // Check wallkick left
                            if (m_stack->checkLeftKickRotation(&m_piece, -1, 0)) {
                                m_piece.pos_x--;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            return;
                        }
                    }
                }
            }

            // check if L wallkick is still possible
            if (m_piece.type == Shape::L) {
                x = m_piece.pos_x - 2;
                y = m_piece.pos_y - 1;
                if (x >= 0 || x < m_stack->m_width) {
                    if (y < m_stack->m_height && y >= 0) {
                        if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                            // Check wallkick right
                            if (m_stack->checkLeftKickRotation(&m_piece, 1, 0)) {
                                m_piece.pos_x++;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            // Check wallkick left
                            if (m_stack->checkLeftKickRotation(&m_piece, -1, 0)) {
                                m_piece.pos_x--;
                                m_piece.orientation = modulo(m_piece.orientation + 1, 4);
                                m_ghost_y = m_stack->getGhostY(&m_piece);
                            }

                            return;
                        }
                    }
                }
            }

            x = m_piece.pos_x - 1;

            if (x >= 0 || x < m_stack->m_width) {
                y = m_piece.pos_y - 1;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_piece.pos_y;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_piece.pos_y + 1;
                if (y < m_stack->m_height && y >= 0) {
                    if (m_stack->m_stack[x + y * m_stack->m_width] > 0) {
                        return;
                    }
                }
            }
        }

        // Check wallkick right
        if (m_stack->checkRightKickRotation(&m_piece, 1, 0)) {
            m_piece.pos_x++;
            m_piece.orientation = modulo(m_piece.orientation - 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }

        // Check wallkick left
        else if (m_stack->checkRightKickRotation(&m_piece, -1, 0)) {
            m_piece.pos_x--;
            m_piece.orientation = modulo(m_piece.orientation - 1, 4);
            m_ghost_y = m_stack->getGhostY(&m_piece);
        }
    }
}

/* Lock down the piece */
void BasePlayer::lockPiece() {
    m_already_dropped = true;
    int pos_x = m_piece.pos_x;
    int pos_y = m_piece.pos_y;
    int x;
    int y;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[m_piece.type][m_piece.orientation][j][i] > 0) {
                x = pos_x - 2 + i;
                y = pos_y - 1 + j;
                m_stack->m_stack[x + m_stack->m_width * y] = 8;
            }
        }
    }

    // TODO optimize depending on piece size
    m_stack->updateOutline(m_piece.pos_y - 1);
    m_stack->updateOutline(m_piece.pos_y);
    m_stack->updateOutline(m_piece.pos_y + 1);
    m_stack->updateOutline(m_piece.pos_y + 2);

    m_lock_color_delay = 2;
    m_drawPiece = false;
    m_drawGhost = false;
}

void BasePlayer::changeLevel(int value, bool line_clear) {
    #warning "changeLevel not finished"

    if (m_level >= m_current_mode->max_level)
        return;

    if (m_level == m_section - 1) {
        if (line_clear) {
            m_level += value;
            m_section = m_current_mode->getSection(m_level);
            //std::cout << "section: " << m_section << std::endl;
            section_display.update(m_section);
            section_display.updateGraphics(m_stack);
        } else {
            return;
        }
    }

    m_level += value;
    level_display.update(m_level);
    level_display.updateGraphics(m_stack);
    m_gravity = m_current_mode->getGravity(m_level);
}

void BasePlayer::updateScore(uint8_t nb_lines, bool bravo) {
    m_combo += (2 * nb_lines) - 2;
    unsigned int bravo_val = (bravo) ? 4 : 1;

    // TODO check torikan for lvl_aft_clear
    unsigned int lvl_aft_clear = m_level + nb_lines;
    uint32_t speed = m_current_mode->getLock(m_level) - m_active_time;
    //score += modes->score(level, nbLines, soft, combo, bravo, sonic, active_time, credits);
    /*std::cout << "level : " << m_level << std::endl;
    std::cout << "nblines : " << (unsigned int) nb_lines << std::endl;
    std::cout << "soft : " << (unsigned int) m_soft << std::endl;
    std::cout << "combo : " << (unsigned int) m_combo << std::endl;
    std::cout << "bravo : " << (unsigned int) bravo_val << std::endl;
    std::cout << "sonic : " << (unsigned int) m_sonic << std::endl;
    std::cout << "active_time : " << m_active_time << std::endl;
    std::cout << "lvl_aft_clear : " << lvl_aft_clear << std::endl;
    std::cout << "speed : " << speed << std::endl;*/

    m_score += m_current_mode->score_func(m_level, nb_lines, m_soft, m_sonic,
                                          m_combo, bravo_val, lvl_aft_clear,
                                          speed);
    //std::cout << "score : " << m_score << std::endl << std::endl;
    score_display.update(m_score);
    score_display.updateGraphics(m_stack);
}

unsigned int BasePlayer::gravity() {
    m_gravity_counter += m_gravity;
    //cout << gravity_counter << endl;
    if (m_gravity_counter >= 256) {
        m_gravity_counter /= 256;
        unsigned int number_down = m_gravity_counter;
        if (number_down == 0)
            return 1;

        m_gravity_counter = 0;
        return number_down;
    }

    return 0;
}

bool BasePlayer::checkLock() {
    if (m_startLock) {
        if (m_lock > m_current_mode->getLock(m_level)) {
            //cout << "lock: " << lock << endl;
            m_lock = 0;
            m_startLock = false;
            return true;
        }
    }
    return false;
}

bool BasePlayer::hasLockStarted() {
    if (m_lock == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool BasePlayer::checkARE() {
    if (m_startARE) {
        m_are++;
        //cout << "ARE: " << are << endl;
        if (m_are > m_current_mode->getARE(m_level)) {
            //cout << "are: " << are << endl;
            m_are = 0;
            m_startARE = false;
            return true;
        }
    }
    return false;
}

bool BasePlayer::checkClear() {
    if (m_startClear) {
        m_clear++;
        //cout << "CLEAR: " << clearDelay << endl;
        if (m_clear > m_current_mode->getClear(m_level)) {
            //cout << "clear: " << clearDelay << endl;
            m_clear = 0;
            m_startClear = false;
            return true;
        }
    }
    return false;
}

bool BasePlayer::checkDASleft() {
    if (m_startDASleft) {
        m_DASleft++;
        //cout << "DAS_LEFT: " << dasLeft << endl;
        if (m_DASleft > m_current_mode->getDAS(m_level)) {
            m_DASleft = m_current_mode->getDAS(m_level);
            return true;
        }
    }
    return false;
}

bool BasePlayer::checkDASright() {
    if (m_startDASright) {
        m_DASright++;
        //cout << "DAS_RIGHT: " << dasRight << endl;
        if (m_DASright > m_current_mode->getDAS(m_level)) {
            m_DASright = m_current_mode->getDAS(m_level);
            return true;
        }
    }
    return false;
}
