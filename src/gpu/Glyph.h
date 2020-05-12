/* Glyph.h - GPU */

#ifndef GLYPH_H
#define GLYPH_H

#include <GPUTypes.h>

#define NB_GLYPHS 256

struct Glyph {
    gpu_float_t x, y;
    gpu_float_t width, height;
    gpu_float_t offset;
};

#endif // GLYPH_H
