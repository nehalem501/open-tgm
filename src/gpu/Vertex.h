/* Vertex.h - GPU */

#ifndef VERTEX_H
#define VERTEX_H

#include <GPUTypes.h>

#define GPU_BLACK { 0.0, 0.0, 0.0, 1.0 }
#define GPU_WHITE { 1.0, 1.0, 1.0, 1.0 }
#define GPU_RED { 1.0, 0.0, 0.0, 1.0 }
#define GPU_GREEN { 0.0, 1.0, 0.0, 1.0 }
#define GPU_BLUE { 0.0, 0.0, 1.0, 1.0 }

#define TOP_LEFT { 0.0, 0.0 }
#define TOP_RIGHT { 1.0, 0.0 }
#define BOTTOM_LEFT { 0.0, 1.0 }
#define BOTTOM_RIGHT { 1.0, 1.0 }

struct ColorRGB {
    gpu_float_t r, g, b;
};

struct ColorRGBA {
    gpu_float_t r, g, b, a;
};

struct TexCoord {
    gpu_float_t u, v;
};

struct Vertex2D {
    gpu_float_t x, y;
    gpu_float_t u, v;
    gpu_float_t r, g, b, a;

    inline void position(gpu_float_t x, gpu_float_t y) {
        this->x = x;
        this->y = y;
    };

    inline void tex_coords(TexCoord uv) {
        this->u = uv.u;
        this->v = uv.v;
    };

    inline void tex_coords(gpu_float_t u, gpu_float_t v) {
        this->u = u;
        this->v = v;
    };

    inline void color(ColorRGB c) {
        color(c.r, c.g, c.b, 1.0);
    };

    inline void color(ColorRGBA c) {
        this->r = c.r;
        this->g = c.g;
        this->b = c.b;
        this->a = c.a;
    };

    inline void color(gpu_float_t r, gpu_float_t g, gpu_float_t b, gpu_float_t a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };
};

#endif // VERTEX_H
