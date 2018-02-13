/* Piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <Global.h>

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

class Piece {
    private:
        tiles_t m_type;
        int m_orientation;

        int m_pos_x;
        int m_pos_y;

    public:
        Piece();
        Piece(tiles_t type, int orientation);
        Piece(tiles_t type, int orientation, int pos_x, int pos_y);

        void locked(Stack *stack);

        inline tiles_t type() { return m_type; };
        inline int orientation() { return m_orientation; };
        inline int pos_x() { return m_pos_x; };
        inline int pos_y() { return m_pos_y; };

        inline void type(tiles_t type) { m_type = type; };
        inline void orientation(int o) { m_orientation = o; };
        inline void pos_x(int pos_x) { m_pos_x = pos_x; };
        inline void pos_y(int pos_y) { m_pos_y = pos_y; };

        inline void init(tiles_t type, int orientation, int pos_x, int pos_y) {
            m_type = type;
            m_orientation = orientation;
            m_pos_x = pos_x;
            m_pos_y = pos_y;
        };

        inline void rotate(int dir, int n) {
            m_orientation = (dir % n + n) % n;
        };

        inline void move(int x, int y) {
            m_pos_x += x;
            m_pos_y += y;
        };
};

#endif
