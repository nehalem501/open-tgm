/* Glyph.h - GPU */

#ifndef GLYPH_H
#define GLYPH_H

#include <GPUTypes.h>

#define NB_GLYPHS 256

struct Glyph {
    gpu_float_t x, y;
    gpu_float_t width, height;
    gpu_float_t offset;

    constexpr Glyph(
        gpu_float_t x,
        gpu_float_t y,
        gpu_float_t width,
        gpu_float_t height,
        gpu_float_t offset) :
            x(x), y(y), width(width), height(height), offset(offset) { }
};

#endif // GLYPH_H
