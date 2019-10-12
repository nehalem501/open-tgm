/* Player.cpp */

#include <stdlib.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <Shapes.h>
#include <Mode.h>
#include <Utils.h>
#include <Stack.h>
#include <core/Game.h>
#include <core/Player.h>

#define OLD_LOCK_COLOR_DELAY 3
#define NEW_LOCK_COLOR_DELAY 2

/* Used at program startup */
void Core::Player::init(::Stack *stack) {
    m_stack = stack;
    m_score_display.init_graphics();
    m_level_display.init_graphics();
    m_section_display.init_graphics();
}

/* Init the field and all the other stuff */
void Core::Player::init(::Stack *stack, Mode *mode) {
    m_stack = stack;
    m_current_mode = mode;

    m_score = 0;
    m_level = 0;

    m_active_time = 0;
    m_gravity = 0;
    m_gravity_counter = 0;
    m_section = mode->section(0);

    m_already_dropped = false;
    m_lock_color_delay = 0;

    m_draw_piece = false;
    m_draw_ghost = false;
    m_start_das_left = false;
    m_start_das_right = false;

    m_ghost_y = 0;
    m_piece_old_y = 0;
    m_next = 0;
    m_state = PlayerState::WAITING;

    m_start_lock = false;
    m_previous_down = false;

    m_are = 0;
    m_combo = 1;
    reset_lock();

    m_sonic = 0;
    m_soft = 0;
    m_clear = 0;

    m_das_left = 0;
    m_das_right = 0;

    m_grade.set(Grade::None);

    m_score_display.init(mode->score_pos_x(), mode->score_pos_y());
    m_level_display.init(mode->level_pos_x(), mode->level_pos_y());
    m_section_display.init(mode->level_target_pos_x(), mode->level_target_pos_y());
    m_section_display.update(m_section);
    m_section_display.update_graphics(stack);

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
    change_level(0, false);
    //nextPiece();
}

/* Init stuff needed to start a new game */
void Core::Player::start_game() {
    m_state = PlayerState::ARE;
    m_line_are = false;
    m_are = m_current_mode->are(0);
}

/* Update game for 1 frame */
void Core::Player::update(int *game_state) {
    bool move_left = false;
    bool move_right = false;
    bool irs = false;

    // DAS charge unmodified during line clear delay
    if (m_state != PlayerState::CLEAR) {
        // Left DAS
        if (input.left()) {
            if (m_start_das_left) {
                if (check_das_left()) {
                    move_left = true;
                }
            } else {
                m_start_das_left = true;
                move_left = true;
            }
        } else {
            if (m_start_das_left) {
                m_start_das_left = false;
                m_das_left = 0;
            }
        }

        // Right DAS
        if (input.right()) {
            if (m_start_das_right) {
                if (check_das_right()) {
                    move_right = true;
                }
            } else {
                m_start_das_right = true;
                move_right = true;
            }
        } else {
            if (m_start_das_right) {
                m_start_das_right = false;
                m_das_right = 0;
            }
        }
    }

    switch (m_state) {
        case PlayerState::WAITING:
            #ifdef DEBUG
            print("WAITING\n");
            #endif

            break;

        case PlayerState::ARE: {
            m_are++;

            #ifdef DEBUG
            if (m_line_are) {
                print("LINE ARE: %d\n", (int) m_are);
            } else {
                print("ARE: %d\n", (int) m_are);
            }
            #endif

            bool are_finished = m_line_are ?
                                (m_are >= m_current_mode->line_are(m_level) + 2):
                                (m_are >= m_current_mode->are(m_level));

            if (are_finished) {
                next_piece();

                m_are = 0;
                m_sonic = 0;
                m_soft = 0;
                m_active_time = 0;

                change_level(1, false);
                m_draw_piece = true;

                // Hide ghost piece after level 100
                if (m_level > 100) {
                    m_draw_ghost = false;
                } else {
                    m_draw_ghost = true;
                }

                m_already_dropped = false;

                int direction = input.irs();
                if (direction) {
                    m_piece.rotate(direction, 4);
                    irs = true;
                    // You cannot do an IRS that will make you die
                    if (!m_stack->check_player_move(&m_piece, 0, 0, 0)) {
                        m_piece.orientation(0);
                        irs = false;
                    }
                }

                // If piece doesn't have room to spawn, it's game over
                if (!m_stack->check_player_move(&m_piece, 0, 0, 0)) {
                    //lockPiece(); // TODO
                    //m_stack->removeGreyBlocks(&m_piece);
                    *game_state = GameState::GAME_OVER_ANIM;
                    m_piece.locked(m_stack);
                    m_stack->remove_grey_blocks(&m_piece);
                    m_stack->reset_outline();
                    m_draw_piece = false;
                    m_draw_ghost = false;
                    return;
                }

                // Update ghost piece
                m_ghost_y = m_stack->get_ghost_y(&m_piece);

                // Reset lock delay
                reset_lock();

                if (m_gravity >= 5120) {
                    // In 20G we have 1 additionnal frame of lock delay
                    // only when the player's piece spawns,
                    // but not in subsequent lock delay resets
                    m_lock = 0;
                }

                // We don't want our piece moved when appearing
                move_left = false;
                move_right = false;

                // New state
                m_state = PlayerState::INGAME;
                m_line_are = false;
            } else {
                break;
            }
        }

        // Maybe unnecessary ?
        /*case PlayerState::NEW_PIECE: {
            break;
        }*/

        case PlayerState::INGAME: {
            #ifdef DEBUG
            print("INGAME\n");
            #endif

            m_piece_old_y = m_piece.pos_y();
            m_active_time++;

            // Rotate Left
            if (!irs && input.rotate_left()) {
                m_piece.rotate_kick(m_stack, &m_ghost_y, 1);
            }

            // Rotate Right
            if (!irs && input.rotate_right()) {
                m_piece.rotate_kick(m_stack, &m_ghost_y, -1);
            }

            // Left
            if (move_left) {
                m_piece.move_leftright(m_stack, &m_ghost_y,  -1);
            }

            // Right
            if (move_right) {
                m_piece.move_leftright(m_stack, &m_ghost_y, 1);
            }

            // Check if piece can go down
            bool can_go_down = m_stack->check_player_move(&m_piece, 0, 1, 0);

            // Compute gravity
            unsigned int number_down = gravity(can_go_down);

            #ifdef DEBUG
            print("Can go down: %s\n", can_go_down ? "true" : "false");
            #endif

            // Down
            if (input.down()) {
                if (m_current_mode->keep_down() || !m_previous_down) {
                    //m_previous_down = true;
                    m_soft++;

                    #ifdef DEBUG
                    print("soft: %d\n", (int) m_soft);
                    #endif

                    if (number_down == 0) {
                        m_piece.move_down(m_ghost_y, 1);
                    }

                    if (!can_go_down) {
                        if (!m_already_dropped) {
                            m_state = PlayerState::LOCK;
                            m_draw_piece = false;
                            if (m_current_mode->old_locking_style()) {
                                goto piece_locked;
                            } else {
                                // Used as darker piece for blink animation
                                m_draw_ghost = true;
                                return;
                            }
                        }
                    } else {
                        if (!m_stack->check_player_move(&m_piece, 0, 1, 0)) {
                            m_previous_down = true;
                            m_state = PlayerState::LOCK;
                            m_draw_piece = false;
                            if (m_current_mode->old_locking_style()) {
                                goto piece_locked;
                            } else {
                                // Used as darker piece for blink animation
                                m_draw_ghost = true;
                                return;
                            }
                        }
                    }
                }
            } else {
                m_previous_down = false;
            }

            // Gravity
            if (can_go_down && number_down) {
                m_sonic = m_piece.move_down(m_ghost_y, number_down);
                // TODO sonic value
            }

            // Sonic Drop
            if (m_current_mode->sonic_drop()) {
                if (input.sonic_drop()) {
                    m_piece.move_down(m_ghost_y, MAX_HEIGHT);
                }
            }

            // Start counting lock delay
            if (!can_go_down) {
                if (m_piece_old_y != m_piece.pos_y()) {
                    reset_lock();
                } else {
                    // Change state if finished counting lock delay
                    if (check_lock()) {
                        reset_lock();
                        m_state = PlayerState::LOCK;
                        m_draw_piece = false;
                        if (m_current_mode->old_locking_style()) {
                            goto piece_locked;
                        } else {
                            // Used as darker piece for blink animation
                            m_draw_ghost = true;
                            return;
                        }
                    }
                }

                // Not restart counting if already doing it
                if (!m_start_lock) {
                    #ifdef DEBUG
                    print("start lock delay\n");
                    #endif

                    start_lock();
                }
            } else {
                if (m_lock) { // Check if lock started
                    if (m_piece_old_y != m_piece.pos_y()) {
                        reset_lock();
                    }
                }
            }

            break;
        }

        case PlayerState::LOCK: {
        piece_locked:
            m_draw_ghost = false;

            #ifdef DEBUG
            print("state: LOCK\n");
            print("piece_pos_y: %d\n", (int) m_piece.pos_y());
            #endif

            // Copy piece to stack/field
            m_piece.locked(m_stack);

            if (m_current_mode->old_locking_style()) {
                m_lock_color_delay = OLD_LOCK_COLOR_DELAY;
                m_state = PlayerState::LOCKED_ANIM_OLD;
                break;
            } else {
                m_lock_color_delay = NEW_LOCK_COLOR_DELAY;

                // TODO optimize depending on piece size
                m_stack->update_outline(m_piece.pos_y() - 2);

                m_stack->update_outline(m_piece.pos_y() - 1);
                m_stack->update_outline(m_piece.pos_y());
                m_stack->update_outline(m_piece.pos_y() + 1);
                m_stack->update_outline(m_piece.pos_y() + 2);

                m_stack->update_outline(m_piece.pos_y() + 3);

                m_state = PlayerState::LOCKED_ANIM_NEW;

                #ifdef DEBUG
                print("state: LOCKED_ANIM_NEW\n");
                #endif
            }
        }

        case PlayerState::LOCKED_ANIM_NEW:
            #ifdef DEBUG
            print("color_delay: %d\n", (int) m_lock_color_delay);
            #endif

            if (m_stack->check_lines(this)) {
                m_state = PlayerState::CLEAR;
            } else {
                if (m_lock_color_delay > 0) {
                    m_lock_color_delay--;
                    return;
                }

                m_stack->remove_grey_blocks(&m_piece);
                m_combo = 1;
                m_state = PlayerState::ARE;
                break;
            }

        case PlayerState::LOCKED_ANIM_OLD:
            #ifdef DEBUG
            print("color_delay: %d\n", (int) m_lock_color_delay);
            #endif

            if (m_lock_color_delay > 0) {
                if (m_lock_color_delay == 1) {
                    m_stack->remove_grey_blocks(&m_piece);
                }

                m_lock_color_delay--;
                return;
            }

            if (m_stack->check_lines(this)) {
                m_state = PlayerState::CLEAR;
            } else {
                m_combo = 1;
                m_state = PlayerState::ARE;
                // Time wasted here counts for ARE in TGM1, so we add it
                m_are += 3;
            }

            // TODO optimize depending on piece size
            // Should be enough to do this only in ARE case, but bug
            // with outline when clearing lines
            m_stack->update_outline(m_piece.pos_y() - 2);

            m_stack->update_outline(m_piece.pos_y() - 1);
            m_stack->update_outline(m_piece.pos_y());
            m_stack->update_outline(m_piece.pos_y() + 1);
            m_stack->update_outline(m_piece.pos_y() + 2);

            m_stack->update_outline(m_piece.pos_y() + 3);

            break;

        case PlayerState::CLEAR: {
            m_clear++;

            #ifdef DEBUG
            print("clear: %d\n", (int) m_clear);
            #endif

            if (m_lock_color_delay > 0) {
                #ifdef DEBUG
                print("color_delay: %d\n", (int) m_lock_color_delay);
                #endif

                m_lock_color_delay--;
            } else if (m_lock_color_delay <= 0) {
                m_stack->remove_grey_blocks(&m_piece);
            }

            if (m_clear >= m_current_mode->clear(m_level)) {
                m_clear = 0;
                m_stack->shift_lines();
                m_line_are = true;
                if (m_current_mode->old_locking_style()) {
                    m_are += 5;
                }
                m_state = PlayerState::ARE;
            }

            break;
        }

        default:
            break;
    }
}

/* Use randomizer and get next piece */
void Core::Player::next_piece() {
    m_piece.spawn(m_next);
    m_piece_old_y = m_piece.pos_y();
    m_active_time = 0;
    m_gravity_counter = 0;

    uint32_t r = 0;

    for (unsigned int i = 0; i < m_current_mode->random_tries(); i++) {
        r = tgm_random(&rand_seed) % NB_TYPES;

        if (r != m_history[0] && r != m_history[1] &&
            r != m_history[2] && r != m_history[3]) {
            break;
        }

        r = tgm_random(&rand_seed) % NB_TYPES;
    }

    m_history[3] = m_history[2];
    m_history[2] = m_history[1];
    m_history[1] = m_history[0];
    m_history[0] = (tiles_t) r;

    m_next = (tiles_t) r;
}

/* Increase level if possible */
void Core::Player::change_level(int value, bool line_clear) {
    #warning "changeLevel not finished"

    // Last level
    if (m_level >= m_current_mode->max_level())
        return;

    // Check for line clear at end of section
    if (m_level == m_section - 1) {
        if (line_clear) {
            m_section = m_current_mode->section(m_level + value);
            m_section_display.update(m_section);
            m_section_display.update_graphics(m_stack);
        } else {
            return;
        }
    }

    m_level += value;

    // Happens if we clear multiple lines at the end of last section
    if (m_level >= m_current_mode->max_level())
        m_level = m_current_mode->max_level();

    m_level_display.update(m_level);
    m_level_display.update_graphics(m_stack);
    m_gravity = m_current_mode->gravity(m_level);
}

/* Update player's score */
void Core::Player::update_score(unsigned int nb_lines, bool bravo) {
    m_combo += (2 * nb_lines) - 2;
    unsigned int bravo_val = (bravo) ? 4 : 1;

    // TODO check torikan for lvl_aft_clear
    // lvl_aft_clear != m_level + nb_lines when finishing the game
    // (300 in easy, 500 torikan in death, 999 in other modes)
    // Implement torikan in Mode using callback like score_func
    unsigned int lvl_aft_clear = m_level + nb_lines;
    uint32_t speed = 0;
    if (m_current_mode->lock(m_level) > m_active_time) {
        speed = m_current_mode->lock(m_level) - m_active_time;
    }

    //score += modes->score(level, nbLines, soft, combo, bravo, sonic, active_time, credits);

    #ifdef DEBUG
    print("level: %d\n", (int) m_level);
    print("nblines: %d\n", (int) nb_lines);
    print("soft: %d\n", (int) m_soft);
    print("combo: %d\n", (int) m_combo);
    print("bravo: %d\n", (int) bravo_val);
    print("sonic: %d\n", (int) m_sonic);
    print("active_time: %d\n", (int) m_active_time);
    print("lvl_aft_clear: %d\n", (int) lvl_aft_clear);
    print("speed: %d\n", (int) speed);
    #endif

    m_score += m_current_mode->score_func(m_level, nb_lines, m_soft, m_sonic,
                                          m_combo, bravo_val, lvl_aft_clear,
                                          speed);
    //std::cout << "score : " << m_score << std::endl << std::endl;

    m_current_mode->grade_func(m_score, 0 /* TODO */, &m_grade);

    m_score_display.update(m_score);
    m_score_display.update_graphics(m_stack);
}

/* Give number of G for current gravity */
unsigned int Core::Player::gravity(bool can_go_down) {
    if (!can_go_down) {
        m_gravity_counter = 0;

        #ifdef DEBUG
        print("gravity: %d\n", (int) m_gravity);
        print("gravity_counter: %d\n", (int) m_gravity_counter);
        #endif

        return 0;
    }

    m_gravity_counter += m_gravity;

    #ifdef DEBUG
    print("gravity_counter: %d\n", (int) m_gravity_counter);
    #endif

    if (m_gravity_counter > 256) {
        unsigned int number_down = m_gravity_counter / 256;

        #ifdef DEBUG
        print("number_down: %d\n", (int) number_down);
        #endif

        if (number_down == 0)
            return 1;

        m_gravity_counter %= 256;
        return number_down;
    }

    return 0;
}

/* Check if lock delay finished */
bool Core::Player::check_lock() {
    if (m_start_lock) {
        // TODO test
        m_lock++;

        #ifdef DEBUG
        print("lock: %d\n", (int) m_lock);
        #endif

        if (m_lock >= m_current_mode->lock(m_level)) {
            return true;
        }
    }
    return false;
}

/* Count DAS frames for left input and check if fully charged */
bool Core::Player::check_das_left() {
    if (m_start_das_left) {
        m_das_left++;

        #ifdef DEBUG
        print("left DAS: %d\n", (int) m_das_left);
        #endif

        if (m_das_left > m_current_mode->das(m_level)) {
            m_das_left = m_current_mode->das(m_level);
            return true;
        }
    }
    return false;
}

/* Count DAS frames for right input and check if fully charged */
bool Core::Player::check_das_right() {
    if (m_start_das_right) {
        m_das_right++;

        #ifdef DEBUG
        print("right DAS: %d\n", (int) m_das_right);
        #endif

        if (m_das_right > m_current_mode->das(m_level)) {
            m_das_right = m_current_mode->das(m_level);
            return true;
        }
    }
    return false;
}
