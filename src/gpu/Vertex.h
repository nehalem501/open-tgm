/* Vertex.h - GPU */

#ifndef VERTEX_H
#define VERTEX_H

#include <GPUTypes.h>

struct Vertex2D {
    gpu_float_t x, y;
    gpu_float_t u, v;
    gpu_float_t r, g, b, a;

    inline void position(gpu_float_t x, gpu_float_t y) {
        this->x = x;
        this->y = y;
    };

    inline void tex_coords(gpu_float_t u, gpu_float_t v) {
        this->u = u;
        this->v = v;
    };

    inline void color(gpu_float_t r, gpu_float_t g, gpu_float_t b, gpu_float_t a) {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    };
};

#endif // VERTEX_H
