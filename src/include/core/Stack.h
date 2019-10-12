/* Stack.h */

#ifndef CORE_STACK_H
#define CORE_STACK_H

#include <string.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Piece.h>
#include <Mode.h>
#include <core/Player.h>
#include <LineClearParticles.h>

#define FILLED_LINES_NB 4

namespace Core {
    class Stack {
        protected:
            int m_filled_lines[FILLED_LINES_NB];
            tiles_t m_outline[MAX_WIDTH * MAX_HEIGHT];

            ::LineClearParticles m_part[FILLED_LINES_NB];

        public:
            int m_pos_x, m_pos_y, m_height, m_width;

            tiles_t m_field[MAX_WIDTH * MAX_HEIGHT];

            Stack();

            void init(int pos_x,
                      int pos_y,
                      int width,
                      int height);

            void start_game(Mode *mode);

            int get_ghost_y(Piece *piece);

            bool check_player_move(Piece *piece,
                                   int new_x,
                                   int new_y,
                                   int new_rotation);

            bool check_bravo();
            bool check_line(unsigned int line);

            void shift_line(unsigned int line);
            void shift_lines();
            bool check_lines(Core::Player *player);
            void remove_line(unsigned int line);

            inline void reset_outline() {
                memset(m_outline, 0, sizeof(tiles_t) * MAX_WIDTH *MAX_HEIGHT);
            };
            void update_outline(unsigned int unsigned_line);

            void remove_grey_blocks(Piece *piece);
    };
}

#endif
