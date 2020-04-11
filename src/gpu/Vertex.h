/* Vertex.h - GPU */

#ifndef VERTEX_H
#define VERTEX_H

#include <GPUTypes.h>

#define GPU_BLACK ColorRGBA(0.0, 0.0, 0.0, 1.0)
#define GPU_WHITE ColorRGBA(1.0, 1.0, 1.0, 1.0)
#define GPU_RED ColorRGBA(1.0, 0.0, 0.0, 1.0)
#define GPU_GREEN ColorRGBA(0.0, 1.0, 0.0, 1.0)
#define GPU_BLUE ColorRGBA(0.0, 0.0, 1.0, 1.0)

#define GPU_TOP_LEFT TexCoord(0.0, 0.0)
#define GPU_TOP_RIGHT TexCoord(1.0, 0.0)
#define GPU_BOTTOM_LEFT TexCoord(0.0, 1.0)
#define GPU_BOTTOM_RIGHT TexCoord(1.0, 1.0)

struct Vector2D {
    Vector2D(gpu_float_t x, gpu_float_t y) : x(x), y(y) { };

    gpu_float_t x, y;
};

struct ColorRGB {
    ColorRGB(gpu_float_t r, gpu_float_t g, gpu_float_t b) : r(r), g(g), b(b) { };

    gpu_float_t r, g, b;
};

struct ColorRGBA {
    ColorRGBA(
        gpu_float_t r,
        gpu_float_t g,
        gpu_float_t b,
        gpu_float_t a) : r(r), g(g), b(b), a(a) { };

    gpu_float_t r, g, b, a;
};

struct TexCoord {
    TexCoord(gpu_float_t u, gpu_float_t v) : u(u), v(v) { };

    gpu_float_t u, v;
};

struct Vertex2D {
    gpu_float_t x, y;
    gpu_float_t u, v;
    gpu_float_t r, g, b, a;

    Vertex2D(
        gpu_float_t x, gpu_float_t y,
        gpu_float_t u, gpu_float_t v,
        gpu_float_t r, gpu_float_t g, gpu_float_t b, gpu_float_t a) :
            x(x), y(y),
            u(u), v(v),
            r(r), g(g), b(b), a(a) { };

    Vertex2D(
        const Vector2D& xy,
        const TexCoord& uv,
        const ColorRGB& rgb) :
            x(xy.x), y(xy.y),
            u(uv.u), v(uv.v),
            r(rgb.r), g(rgb.g), b(rgb.b), a(1.0) { };

    Vertex2D(
        const Vector2D& xy,
        const TexCoord& uv,
        const ColorRGBA& rgba) :
            x(xy.x), y(xy.y),
            u(uv.u), v(uv.v),
            r(rgba.r), g(rgba.g), b(rgba.b), a(rgba.a) { };

    inline void position(gpu_float_t x, gpu_float_t y) {
        this->x = x;
        this->y = y;
    };

    inline void tex_coords(const TexCoord& uv) {
        this->u = uv.u;
        this->v = uv.v;
    };

    inline void tex_coords(gpu_float_t u, gpu_float_t v) {
        this->u = u;
        this->v = v;
    };

    inline void color(const ColorRGB& c) {
        color(c.r, c.g, c.b, 1.0);
    };

    inline void color(const ColorRGBA& c) {
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
