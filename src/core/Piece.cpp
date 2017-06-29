/* Piece.cpp */

#include <Global.h>
#include <Piece.h>

Piece::Piece() : type(0), orientation(0) {
}

Piece::Piece(tiles_t t, int o) : type(t), orientation(o) {
}

Piece::Piece(tiles_t t, int o, int x, int y) : type(t),
    orientation(o), pos_x(x), pos_y(y) {
}
