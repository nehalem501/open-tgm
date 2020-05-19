/* Coordinates.h */

#ifndef COORDINATES_H
#define COORDINATES_H

#include <Global.h>
#include <Position.h>

struct Coordinates {
    int x, y;
    Layout layout;

    Coordinates(int x, int y) : x(x), y(y), layout(Layouts::NONE) { }
    Coordinates(int x, int y, Layout layout) : x(x), y(y), layout(layout) { }
    Coordinates(const Coordinates& coordinates) :
        x(coordinates.x),
        y(coordinates.y),
        layout(coordinates.layout) { }

    inline int to_position_x() const { return x * tile_size; }
    inline int to_position_y() const { return y * tile_size; }
    inline Position to_position() const {
        return Position(to_position_x(), to_position_y(), layout);
    }

    inline Coordinates& operator=(const Coordinates& coordinates) {
        x = coordinates.x;
        y = coordinates.y;
        layout = coordinates.layout;
        return *this;
    }
};

#endif // COORDINATES_H
