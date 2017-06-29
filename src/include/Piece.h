/* Piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <Global.h>

class Piece {
    public:
        tiles_t type;
        int orientation;

        int pos_x;
        int pos_y;

        Piece();
        Piece(tiles_t t, int o);
        Piece(tiles_t t, int o, int x, int y);
};

#endif
