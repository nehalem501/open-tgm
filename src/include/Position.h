/* Position.h */

#ifndef POSITION_H
#define POSITION_H

#include <stdint.h>

typedef uint8_t Layout;

namespace Layouts {
    enum {
        NONE = 0,
        CENTERED = 1
    };
}

struct Position {
    int x, y;

    constexpr Position(int x, int y) : x(x), y(y) { }

    inline Position operator+(const Position& position) {
        return Position(position.x + x, position.y + y);
    }
};

#endif // POSITION_H
