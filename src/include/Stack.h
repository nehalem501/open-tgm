/* Stack.h */

#ifndef STACK_H
#define STACK_H

#include <string.h>
#include <TargetTypes.h>
#include <Position.h>
#include <Global.h>
#include <LineClearParticles.h>
#include <StackImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;
class Piece;
class Player;

#define FILLED_LINES_NB 4 // TODO 8 for BIG mode

class Stack {
    public:
        Stack();

        void draw() const;

        void init(Position &parent, int width, int height);

        void start_game(Mode *mode);

        int get_ghost_y(Piece *piece);

        bool check_player_move(
            Piece *piece,
            int new_x,
            int new_y,
            int new_rotation);

        bool check_bravo();
        bool check_line(unsigned int line);

        void shift_line(unsigned int line);
        void shift_lines();
        bool check_lines(Player& player);
        void remove_line(unsigned int line);

        inline void reset_outline() {
            memset(m_outline, 0, sizeof(tiles_t) * MAX_WIDTH * MAX_HEIGHT);
        };
        void update_outline(unsigned int unsigned_line);

        void remove_grey_blocks(const Piece& piece);

        inline int height() { return m_height; };
        inline int width() { return m_width; };

        inline tiles_t* field() { return m_field; };
        inline tiles_t* outline() { return m_outline; };

        inline tiles_t block(int x, int y) {
            return m_field[x + m_width * y];
        };
        inline void update_block(int x, int y, tiles_t value) {
            m_field[x + m_width * y] = value;
        };

        inline const Position& position() { return m_parent; };

    private:
        int m_height, m_width;
        Position &m_parent;

        tiles_t m_field[MAX_WIDTH * MAX_HEIGHT];
        tiles_t m_outline[MAX_WIDTH * MAX_HEIGHT];

        int m_filled_lines[FILLED_LINES_NB];

        LineClearParticles m_particles[FILLED_LINES_NB];

        StackImpl m_implementation;
};

#endif // STACK_H
