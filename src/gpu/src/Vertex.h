/* Vertex.h - GPU */

#ifndef VERTEX_H
#define VERTEX_H

#include <GPUTypes.h>
#include <GPUVertex.h>
#include <TargetTypes.h>

#define GPU_BLACK ColorRGBA(0.0f, 0.0f, 0.0f, 1.0f)
#define GPU_WHITE ColorRGBA(1.0f, 1.0f, 1.0f, 1.0f)
#define GPU_RED   ColorRGBA(1.0f, 0.0f, 0.0f, 1.0f)
#define GPU_GREEN ColorRGBA(0.0f, 1.0f, 0.0f, 1.0f)
#define GPU_BLUE  ColorRGBA(0.0f, 0.0f, 1.0f, 1.0f)

#define GPU_TOP_LEFT TexCoord(0.0, 0.0)
#define GPU_TOP_RIGHT TexCoord(1.0, 0.0)
#define GPU_BOTTOM_LEFT TexCoord(0.0, 1.0)
#define GPU_BOTTOM_RIGHT TexCoord(1.0, 1.0)

struct Point2D : Point2DImpl {
    constexpr Point2D(float x, float y) : Point2DImpl(x, y) { }
    constexpr Point2D(const Point2DImpl& point) : Point2DImpl(point.x(), point.y()) { }
};

struct Size2D : Size2DImpl {
    constexpr Size2D(float width, float height) : Size2DImpl(width, height) { }
    constexpr Size2D(const Size2DImpl& size) : Size2DImpl(size.width(), size.height()) { }
};

struct ColorRGBA : ColorRGBAImpl {
    constexpr ColorRGBA(float r, float g, float b, float a) : ColorRGBAImpl(r, g, b, a) { }
    constexpr ColorRGBA(const ColorRGBAImpl& color) : ColorRGBAImpl(color.r(), color.g(), color.b(), color.a()) { }
};

struct TexCoord : TexCoordImpl {
    constexpr TexCoord(float u, float v) : TexCoordImpl(u, v) { }
    constexpr TexCoord(const TexCoordImpl& texcoords) : TexCoordImpl(texcoords.u(), texcoords.v()) { }
};

struct Vertex2D : Vertex2DImpl {
    constexpr Vertex2D() : Vertex2DImpl(Point2D(0, 0), TexCoord(0, 0), ColorRGBA(0, 0, 0, 0)) { }

    constexpr Vertex2D(
        const Point2D& xy,
        const TexCoord& uv,
        const ColorRGBA& rgba) : Vertex2DImpl(xy, uv, rgba) { }

    constexpr Point2D position() const { return xy; }
    constexpr void position(const Point2D& xy) { this->xy = xy; }

    constexpr TexCoord tex_coords() const { return uv; }
    constexpr void tex_coords(const TexCoord& uv) { this->uv = uv; }

    constexpr ColorRGBA color() const { return rgba; }
    constexpr void color(const ColorRGBA& rgba) { this->rgba = rgba; }

    constexpr void clear() {
        xy.x(0);
        xy.x(0);
        uv.u(0);
        uv.v(0);
        rgba.r(0);
        rgba.g(0);
        rgba.b(0);
        rgba.a(0);
    }

    constexpr float x() const { return xy.x(); }
    constexpr void x(float x) { xy.x(x); }
    constexpr void x_add(float value) { xy.x(x() + value); }

    constexpr float y() const { return xy.y(); }
    constexpr void y(float y) { xy.y(y); }
    constexpr void y_add(float value) { xy.y(y() + value); }

    constexpr float u() const { return uv.u(); }
    constexpr void u(float u) { uv.u(u); }

    constexpr float v() const { return uv.v(); }
    constexpr void v(float v) { uv.v(v); }

    constexpr float r() const { return rgba.r(); }
    constexpr void r(float r) { rgba.r(r); }

    constexpr float g() const { return rgba.g(); }
    constexpr void g(float g) { rgba.g(g); }

    constexpr float b() const { return rgba.b(); }
    constexpr void b(float b) { rgba.b(b); }

    constexpr float a() const { return rgba.a(); }
    constexpr void a(float a) { rgba.a(a); }
};

#endif // VERTEX_H
