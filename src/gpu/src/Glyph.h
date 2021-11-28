/* Glyph.h - GPU */

#ifndef GLYPH_H
#define GLYPH_H

#include <GPUTypes.h>

#define NB_GLYPHS 256

struct Glyph {
    gpu_coord_t x, y;
    gpu_coord_t width, height;
    gpu_coord_t offset;

    constexpr Glyph() : x(0), y(0), width(0), height(0), offset(0) { }

    constexpr Glyph(
        gpu_coord_t x,
        gpu_coord_t y,
        gpu_coord_t width,
        gpu_coord_t height,
        gpu_coord_t offset) :
            x(x), y(y), width(width), height(height), offset(offset) { }
};

#endif // GLYPH_H
