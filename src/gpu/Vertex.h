/* Vertex.h - GPU */

#ifndef VERTEX_H
#define VERTEX_H

#include <TargetTypes.h>

struct Vertex2D {
    gpu_float_t x, y;
    gpu_float_t u, v;
    gpu_float_t r, g, b, a;
};

/*struct Vertex3D {
    gpu_float_t x, y, z;
    gpu_float_t r, g, b, a;
    gpu_float_t u, v;
};*/

#endif // VERTEX_H
