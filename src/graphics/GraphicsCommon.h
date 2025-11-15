/* GraphicsCommon.h - Graphics */

#ifndef GRAPHICS_COMMON_H
#define GRAPHICS_COMMON_H

#include <stddef.h>
#include <stdint.h>
#include "Graphics.h"

struct Image {
    unsigned int width;
    unsigned int height;
    Buffer buffer;
};

struct ColorHSL;

struct Color {
    float r, g, b, a;

    ColorHSL to_hsl();
    static Color from_rgba8(uint8_t* data);
};

struct BlocksSwatch {
    Color light, regular, dark;
};

struct ColorHSL {
    float h, s, l, a;

    Color to_rgb();
};

struct Position {
    unsigned int x;
    unsigned int y;
};

/*struct Size {
    unsigned int width;
    unsigned int height;
};*/

template <typename T>
T bit_ceil(T v) {
    T c = 0b1;
    while (c < v) {
        c <<= 1;
    }
    return c;
}

//void insert_image(Position& position, Image& source, Image& destination);
//void fill_image(Position& position, Size& size, Image& destination);

#endif // GRAPHICS_COMMON_H
