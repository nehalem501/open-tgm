/* Stack.h */

#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <TargetTypes.h>
#include <Piece.h>
#include <Player.h>
#include <LineClearParticles.h>
#include <StackImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;

#define FILLED_LINES_NB 4 // TODO 8 for BIG mode

class Stack {
    public:
        Stack();

        void draw();

        void init(int pos_x, int pos_y, int width, int height);

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
        bool check_lines(Player *player);
        void remove_line(unsigned int line);

        inline void reset_outline() {
            memset(m_outline, 0, sizeof(tiles_t) * MAX_WIDTH * MAX_HEIGHT);
        };
        void update_outline(unsigned int unsigned_line);

        void remove_grey_blocks(Piece *piece);

    private:
        int m_height, m_width;
        Position *m_parent;

        tiles_t m_field[MAX_WIDTH * MAX_HEIGHT];
        tiles_t m_outline[MAX_WIDTH * MAX_HEIGHT];

        int m_filled_lines[FILLED_LINES_NB];

        LineClearParticles m_part[FILLED_LINES_NB];

        StackImpl m_implementation;
};

#endif // STACK_H
