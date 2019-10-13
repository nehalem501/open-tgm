/* Piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <TargetTypes.h>

/* Forward declarations to avoid dependency hell */
class Stack;

class Piece {
    public:
        Piece();
        Piece(tiles_t type, int orientation);
        Piece(tiles_t type, int orientation, int pos_x, int pos_y);

        void locked(Stack *stack);

        inline tiles_t type() const { return m_type; };
        inline int orientation() const { return m_orientation; };
        inline int pos_x() const { return m_pos_x; };
        inline int pos_y() const { return m_pos_y; };

        inline void type(tiles_t type) { m_type = type; };
        inline void orientation(int o) { m_orientation = o; };
        inline void pos_x(int pos_x) { m_pos_x = pos_x; };
        inline void pos_y(int pos_y) { m_pos_y = pos_y; };

        inline void spawn(tiles_t type) {
            m_type = type;
            m_orientation = 0;
            m_pos_x = 5;
            m_pos_y = 2;
        };

        inline void rotate(int dir, int n) {
            m_orientation = (dir % n + n) % n;
        };

        void move_leftright(Stack *stack, int *ghost_y, int amount);
        int move_down(int ghost_y, int amount);
        void rotate_kick(Stack *stack, int *ghost_y, int rotation);

    private:
        tiles_t m_type;
        int m_orientation;

        int m_pos_x;
        int m_pos_y;

        inline void move(int x, int y) {
            m_pos_x += x;
            m_pos_y += y;
        };
};

#endif // PIECE_H
