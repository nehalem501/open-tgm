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
    Layout layout;

    Position(int x, int y) : x(x), y(y), layout(Layouts::NONE) { }
    Position(int x, int y, Layout layout) : x(x), y(y), layout(layout) { }
};

#endif // POSITION_H
