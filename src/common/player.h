/* player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include "piece.h"
#include "input.h"
#include "stack.h"
#include "digits.h"


#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Player : public sf::Drawable {
#else
class Player {
#endif
    private:
        Piece m_piece;
    
    public:
        uint32_t m_score;
        unsigned int m_level;
    
    private:
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
        void initGraphics();

        void update();
        void updateGraphics();

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
        
        void changeLevel(int value, bool lineClear);
        void updateScore(int nbLines, bool bravo);
        
    private:
        bool checkLock();
        bool hasLockStarted();
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
        
    #ifdef TARGET_SFML
    public:
        void updateSize(sf::Vector2u screenSize);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::VertexArray m_next_vertices;
        sf::VertexArray m_piece_vertices;
        sf::VertexArray m_ghost_vertices;
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};

#endif
