/* Coordinates.h */

#ifndef COORDINATES_H
#define COORDINATES_H

#include <Position.h>
#include <TargetTypes.h>

struct Coordinates {
    int x, y;

    constexpr Coordinates(int x, int y) : x(x), y(y) { }

    inline int to_position_x() const { return x * Global::tile_size; }
    inline int to_position_y() const { return y * Global::tile_size; }

    inline Position to_position() const {
        return Position(to_position_x(), to_position_y());
    }

    inline Coordinates operator+(const Coordinates& coordinates) {
        return Coordinates(coordinates.x + x, coordinates.y + y);
    }

    inline bool operator==(const Coordinates& coordinates) const {
        return x == coordinates.x && y == coordinates.y;
    }

    inline bool operator!=(const Coordinates& coordinates) const {
        return !(*this == coordinates);
    }
};

#ifdef DEBUG
void printd_internal(const Coordinates& coordinates);
#endif

#endif // COORDINATES_H
