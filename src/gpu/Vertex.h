/* Vertex.h */

#ifndef VERTEX_H
#define VERTEX_H

#include <TargetTypes.h>

struct Vertex2D {
    gpu_float_t x, y;
    gpu_float_t r, g, b, a;
    gpu_float_t u, v;
};

struct Vertex2DNoColour {
    gpu_float_t x, y;
    gpu_float_t u, v;
};

struct Vertex2DNoTexture {
    gpu_float_t x, y;
    gpu_float_t r, g, b, a;
};

struct Vertex3D {
    gpu_float_t x, y, z;
    gpu_float_t r, g, b, a;
    gpu_float_t u, v;
};

struct Vertex3DNoColor {
    gpu_float_t x, y, z;
    gpu_float_t u, v;
};

struct Vertex3DNoTexture {
    gpu_float_t x, y, z;
    gpu_float_t r, g, b, a;
};

#endif // VERTEX_H

