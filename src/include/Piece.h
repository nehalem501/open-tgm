/* Piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <TargetTypes.h>
#include <Coordinates.h>
#include <Shapes.h>

/* Forward declarations to avoid dependency hell */
class Stack;

class Piece {
    public:
        Piece();
        Piece(tiles_t type, int orientation);
        Piece(tiles_t type, int orientation, Coordinates m_coordinates);

        void locked(Stack *stack);

        inline tiles_t type() const { return m_type; }
        inline int orientation() const { return m_orientation; }
        inline int position_x() const { return m_coordinates.x; } // TODO
        inline int position_y() const { return m_coordinates.y; }

        inline void type(tiles_t type) { m_type = type; }
        inline void orientation(int o) { m_orientation = o; }
        inline void position_x(int pos_x) { m_coordinates.x = pos_x; } // TODO
        inline void position_y(int pos_y) { m_coordinates.y = pos_y; }

        inline const tiles_t* tiles() const {
            return PIECES[m_type][m_orientation];
        }

        inline void spawn(tiles_t type) {
            m_type = type;
            m_orientation = 0;
            m_coordinates.x = 5;
            m_coordinates.y = 2;
        }

        inline void rotate(int dir, int n) {
            m_orientation = (dir % n + n) % n;
        }

        void move_leftright(Stack *stack, int *ghost_y, int amount);
        int move_down(int ghost_y, int amount);
        void rotate_kick(Stack *stack, int *ghost_y, int rotation);

    private:
        Coordinates m_coordinates;
        int m_orientation;
        tiles_t m_type;

        inline void move(int x, int y) {
            m_coordinates.x += x;
            m_coordinates.y += y;
        }
};

#endif // PIECE_H
