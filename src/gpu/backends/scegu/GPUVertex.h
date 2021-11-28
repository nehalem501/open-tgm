/* GPUVertex.h - SCEGU */

#ifndef GPU_VERTEX_SCEGU_H
#define GPU_VERTEX_SCEGU_H

#include "GPUTypes.h"

class Point2DImpl {
    public:
        constexpr Point2DImpl(float x, float y) : m_x(x), m_y(y), m_z(0) { }

        constexpr float x() const { return m_x; }
        constexpr void x(float x) { m_x = x; }

        constexpr float y() const { return m_y; }
        constexpr void y(float y) { m_y = y; }

    private:
        gpu_coord_t m_x, m_y, m_z;
};

class Size2DImpl {
    public:
        constexpr Size2DImpl(float width, float height) : m_width(width), m_height(height) { }

        constexpr float width() const { return m_width; }
        constexpr void width(float width) { m_width = width; }

        constexpr float height() const { return m_height; }
        constexpr void height(float height) { m_height = height; }

    private:
        gpu_coord_t m_width, m_height;
};

class ColorRGBAImpl {
    public:
        constexpr ColorRGBAImpl(
            float r,
            float g,
            float b,
            float a) :
                m_r(float_to_gpu_color(r)),
                m_g(float_to_gpu_color(g)),
                m_b(float_to_gpu_color(b)),
                m_a(float_to_gpu_color(a)) { }

        constexpr float r() const { return gpu_color_to_float(m_r); }
        constexpr void r(float r) { m_r = float_to_gpu_color(r); }

        constexpr float g() const { return gpu_color_to_float(m_g); }
        constexpr void g(float g) { m_g = float_to_gpu_color(g); }

        constexpr float b() const { return gpu_color_to_float(m_b); }
        constexpr void b(float b) { m_b = float_to_gpu_color(b); }

        constexpr float a() const { return gpu_color_to_float(m_a); }
        constexpr void a(float a) { m_a = float_to_gpu_color(a); }

    private:
        static constexpr gpu_color_t float_to_gpu_color(float color) {
            return (gpu_color_t) (color * (float) 255.0f);
        }

        static constexpr float gpu_color_to_float(gpu_color_t color) {
            return ((float) color) / 255.0f;
        }

        gpu_color_t m_r, m_g, m_b, m_a;
};

class TexCoordImpl {
    public:
        constexpr TexCoordImpl(
            float u,
            float v) : m_u(u), m_v(v) { }

        constexpr float u() const { return m_u; }
        constexpr void u(float u) { m_u = u; }

        constexpr float v() const { return m_v; }
        constexpr void v(float v) { m_v = v; }

    private:
        gpu_texcoord_t m_u, m_v;
};

struct Vertex2DImpl {
    TexCoordImpl uv;
    ColorRGBAImpl rgba;
    Point2DImpl xy;

    constexpr Vertex2DImpl(
        const Point2DImpl& xy,
        const TexCoordImpl& uv,
        const ColorRGBAImpl& rgba) : uv(uv), rgba(rgba), xy(xy) { }
};

#endif // GPU_VERTEX_SCEGU_H
