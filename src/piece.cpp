/* piece.cpp */

#include <stdint.h>
#include "piece.h"

Piece::Piece() : type(0),
                 orientation(0) {
}

Piece::Piece(int8_t t, int8_t o) : type(t),
                             orientation(o) {
}

Piece::Piece(int8_t t, int8_t o, int8_t x, int8_t y) : type(t),
                             orientation(o),
                             pos_x(x),
                             pos_y(y) {
}

