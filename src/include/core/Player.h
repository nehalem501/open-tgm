/* Player.h */

#ifndef CORE_PLAYER_H
#define CORE_PLAYER_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <stdint.h>
#include <Mode.h>
#include <Piece.h>
#include <Digits.h>

namespace PlayerState {
    enum {
        WAITING = 0,
        ARE,
        NEW_PIECE,
        INGAME,
        LOCK,
        LOCKED_ANIM,
        CLEAR,
    };
}

namespace Core {
    class Player {
        public:
            ::Piece m_piece;

        protected:
            ::Digits m_score_display;
            ::Digits m_level_display;
            ::Digits m_section_display;

        public:
            uint32_t m_score;
            unsigned int m_level;

        protected:
            ::Stack *m_stack;
            Mode *m_current_mode;

            tiles_t m_history[4];

            unsigned int m_active_time, m_gravity, m_section, m_gravity_counter;

            int m_ghost_y, m_piece_old_y, m_lock_color_delay;
            int m_state;

            unsigned int m_are, m_line_are, m_lock, m_combo;
            unsigned int m_sonic, m_soft, m_clear;
            unsigned int m_das_left, m_das_right;

            tiles_t m_next;

            bool m_draw_piece, m_draw_ghost;
            bool m_start_das_left, m_start_das_right;

            bool m_start_are, m_start_clear, m_start_lock;
            bool m_previous_down;
            /*bool m_rotLeft, m_rotRight;*/

        public:
            bool m_already_dropped;//, m_drawPiece;

            void init(::Stack *stack);
            void init(::Stack *stack, Mode *mode);

            void start_game();

            inline void reset_level() {
                m_level = 0;
                m_level_display.update(0);
                m_level_display.update_graphics(m_stack);
            };

            void update(int *game_state);

            void next_piece();

            void move(int x, int y);
            void move_sonic();

            //void rotateLeft();
            //void rotateRight();
            void rotate(int rotation);

            //void lockPiece();
            //inline void startClear() { m_startClear = true; };
            //inline void stopClear() { m_startClear = false; };

            //inline void startARE() { m_startARE = true; };
            //inline void stopARE() { m_startARE = false; };

            inline void set_combo(int value) { m_combo = value; };
            //inline void stopARE() { m_startARE = false; };

            void change_level(int value, bool line_clear);
            void update_score(unsigned int nb_lines, bool bravo);

        protected:
            bool check_lock();

            inline void reset_lock() {
                #ifdef DEBUG
                std::cout << "reset lock" << std::endl;
                #endif

                m_start_lock = false;
                m_lock = 0;
            };

            inline void start_lock() { m_start_lock = true; m_lock++; };

            //bool checkClear();
            //inline bool notInClear() { return !m_startClear; };

            //bool checkARE();
            //inline bool notInARE() { return !m_startARE; };
            //inline bool inARE() { return !m_startARE; };

            bool check_das_left();
            bool check_das_right();

            unsigned int gravity(bool can_go_down);

            /*inline bool canRotateRight() { return m_rotRight; };
            inline void canRotateRightStart() { m_rotRight = false; };
            inline void canRotateRightStop() { m_rotRight = true; };

            inline bool canRotateLeft() { return m_rotLeft; };
            inline void canRotateLeftStart() { m_rotLeft = false; };
            inline void canRotateLeftStop() { m_rotLeft = true; };

            inline bool canIRSLeft() { return !m_rotLeft; };
            inline bool canIRSRight() { return !m_rotRight; };*/
    };
}

#endif
