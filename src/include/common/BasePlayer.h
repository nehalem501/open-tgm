/* BasePlayer.h */

#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <stdint.h>
#include <Mode.h>
#include <Piece.h>
#include <Digits.h>

class BasePlayer {
    protected:
        Piece m_piece;
        Digits score_display;
        Digits level_display;
        Digits section_display;

    public:
        uint32_t m_score;
        unsigned int m_level;

    protected:
        Stack *m_stack;
        Mode *m_current_mode;

        int8_t m_history[4];

        unsigned int m_active_time, m_gravity, m_section, m_gravity_counter;

        bool m_drawPiece, m_drawGhost;
        bool m_startDASleft, m_startDASright;

        bool m_startARE, m_startClear, m_startLock;
        bool m_rotLeft, m_rotRight;

        int8_t m_next, m_ghost_y, m_piece_old_y;
        int8_t m_lock_color_delay;

        uint8_t m_are, m_line_are, m_lock, m_combo;

        uint8_t m_sonic, m_soft, m_clear;

        uint8_t m_DASleft, m_DASright;

    public:
        bool m_already_dropped;//, m_drawPiece;

        void init(Stack *stack);
        void init(Stack *stack, Mode *mode);

        void startGame();

        void update(int8_t *game_state);

        void nextPiece();

        void move(int x, int y);
        void moveDrop();

        void rotateLeft();
        void rotateRight();

        void lockPiece();
        inline void startClear() { m_startClear = true; };
        inline void stopClear() { m_startClear = false; };

        inline void startARE() { m_startARE = true; };
        inline void stopARE() { m_startARE = false; };

        inline void setCombo(uint8_t value) { m_combo = value; };
        //inline void stopARE() { m_startARE = false; };

        void changeLevel(int value, bool line_clear);
        void updateScore(uint8_t nb_lines, bool bravo);

    protected:
        bool checkLock();
        inline void resetLock() { m_lock = 0; };
        inline void startLock() { m_startLock = true; m_lock++; };

        bool checkClear();
        inline bool notInClear() { return !m_startClear; };

        bool checkARE();
        inline bool notInARE() { return !m_startARE; };

        bool checkDASleft();
        bool checkDASright();

        unsigned int gravity();

        inline bool canRotateRight() { return m_rotRight; };
        inline void canRotateRightStart() { m_rotRight = false; };
        inline void canRotateRightStop() { m_rotRight = true; };

        inline bool canRotateLeft() { return m_rotLeft; };
        inline void canRotateLeftStart() { m_rotLeft = false; };
        inline void canRotateLeftStop() { m_rotLeft = true; };

        inline bool canIRSLeft() { return !m_rotLeft; };
        inline bool canIRSRight() { return !m_rotRight; };
};

#endif
