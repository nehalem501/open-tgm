/* Stack.h */

#ifndef CORE_STACK_H
#define CORE_STACK_H

#include <stdint.h>
#include <Global.h>
#include <Piece.h>
#include <Mode.h>
#include <core/Player.h>
#include <LineClearParticles.h>

/* Forward declarations to avoid dependency hell */
class BasePlayer;
typedef PlayerImpl Player;

#define FILLED_LINES_NB 4

namespace Core {
    class Stack {
        protected:
            int m_active_particles;

            int m_filled_lines[FILLED_LINES_NB];
            tiles_t m_outline[MAX_WIDTH * MAX_HEIGHT];

            ::LineClearParticles m_part0, m_part1;
            ::LineClearParticles m_part2, m_part3;

        public:
            int m_pos_x, m_pos_y, m_height, m_width;

            tiles_t m_field[MAX_WIDTH * MAX_HEIGHT];

            Stack();
            void init(int pos_x, int pos_y, int width, int height);
            void startGame(Mode *mode);

            int getGhostY(Piece *piece);

            bool checkNewPosition(Piece *piece, int new_x, int new_y,
                                  int new_rotation);

            /*bool checkMove(Piece *piece, int x, int y);

            bool checkLeftRotation(Piece *piece);
            bool checkLeftKickRotation(Piece *piece, int x_offset, int y_offset);

            bool checkRightRotation(Piece *piece);
            bool checkRightKickRotation(Piece *piece, int x_offset, int y_offset);*/

            void shiftLine(unsigned int line);
            void shiftLines();
            void checkLines(Core::Player *player);
            void removeLine(unsigned int line);

            void updateOutline(unsigned int unsigned_line);

            void removeGreyBlocks(Piece *piece);
    };
}

#endif
