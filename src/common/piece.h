/* piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <stdint.h>


class Piece {
    public:
        int8_t type;
        int8_t orientation;
        
        int8_t pos_x;
        int8_t pos_y;

        Piece();
        Piece(int8_t t, int8_t o);
        Piece(int8_t t, int8_t o, int8_t x, int8_t y);
};

#endif
