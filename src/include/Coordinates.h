/* Coordinates.h */

#ifndef COORDINATES_H
#define COORDINATES_H

#include <Global.h>
#include <Position.h>

struct Coordinates {
    int x, y;

    Coordinates(int x, int y) : x(x), y(y) { }
    Coordinates(const Coordinates& coordinates) :
        x(coordinates.x),
        y(coordinates.y) { }

    inline int to_position_x() const { return x * tile_size; }
    inline int to_position_y() const { return y * tile_size; }
    inline Position to_position() const {
        return Position(to_position_x(), to_position_y());
    }

    inline Coordinates operator+(const Coordinates& coordinates) {
        return Coordinates(coordinates.x + x, coordinates.y + y);
    }

    inline Coordinates& operator=(const Coordinates& coordinates) {
        x = coordinates.x;
        y = coordinates.y;
        return *this;
    }
};

#endif // COORDINATES_H
