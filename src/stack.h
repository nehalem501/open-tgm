/* stack.h */

#ifndef STACK_H
#define STACK_H

#define FILLED_LINES_NB 4

#include <stdint.h>
#include "global.h"
#include "piece.h"
#include "lineclearparticle.h"
#include "mode.h"
#include "player.h"

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif


#ifdef TARGET_SFML
class Stack : public sf::Drawable {
#else
class Stack {
#endif
    private: 
        int m_active_particles;

        int8_t m_filled_lines[FILLED_LINES_NB];        
        int8_t m_outline[MAX_WIDTH * MAX_HEIGHT];

        LineClearParticle m_part0, m_part1;
        LineClearParticle m_part2, m_part3;

    public:
        int m_pos_x, m_pos_y;
        int m_height, m_width;
        int8_t m_stack[MAX_WIDTH * MAX_HEIGHT];
            
        Stack();
        void init(int pos_x, int pos_y, int width, int height);
        void initGraphics();
        void startGame(Mode *mode);
        
        void updateGraphics();
        
        int8_t getGhostY(Piece *piece);
        
        bool checkMove(Piece *piece, int x, int y);
        
        bool checkLeftRotation(Piece *piece);
        bool checkLeftKickRotation(Piece *piece, int x_offset, int y_offset);

        bool checkRightRotation(Piece *piece);
        bool checkRightKickRotation(Piece *piece, int x_offset, int y_offset);

        void shiftLines();
        void checkLines(Player *player);
    
        void removeGreyBlocks(Piece *piece);

    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
        sf::VertexArray m_vertices;
        sf::VertexArray m_vertices_outline;
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};
#endif

