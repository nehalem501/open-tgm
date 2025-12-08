/* Position.h */

#ifndef POSITION_H
#define POSITION_H

#include <stdint.h>

typedef uint8_t Layout;

namespace Layouts {
    enum {
        NONE = 0b00,
        H_CENTER = 0b01,
        V_CENTER = 0b10,
        //CENTERED = 0b11
    };
}

struct Position {
    int x, y;

    constexpr Position(int x, int y) : x(x), y(y) { }

    inline Position operator+(const Position& position) {
        return Position(position.x + x, position.y + y);
    }

    inline bool operator==(const Position& position) const {
        return x == position.x && y == position.y;
    }

    inline bool operator!=(const Position& position) const {
        return !(*this == position);
    }
};

#ifdef DEBUG
void printd_internal(const Position& position);
#endif

#endif // POSITION_H
