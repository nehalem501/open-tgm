/* StaticVertexArray2D.h - GPU */

#ifndef STATIC_VERTEX_ARRAY_2D_H
#define STATIC_VERTEX_ARRAY_2D_H

#include <stddef.h>
#include <TargetTypes.h>
#include "Debug.h"
#include <VertexArray2DImpl.h>
#include "Vertex.h"
#include "Texture.h"

template <size_t N>
class StaticVertexArray2D {
    private:
        VertexArray2DImpl m_implementation;

    public:
        Vertex2D (&vertices)[N];

        StaticVertexArray2D(TextureID texture) :
                m_implementation(texture, N),
                vertices(*((Vertex2D(*)[N]) m_implementation.m_vertices)) {
            printd(DebugCategory::GPU_VERTICES, "StaticVertexArray2D<", N,"> constructor");
        };

        inline void move(float x, float y) {
            for (size_t i = 0; i < N; i++) {
                vertices[i].x_add(x);
                vertices[i].y_add(y);
            }
        };

        inline void texture(TextureID texture) {
            printd(DebugCategory::GPU_VERTICES,
                "StaticVertexArray2D: Replace texture: this=", (void*) this,
                ", previous=", m_implementation.m_texture,
                ", new=", texture);
            m_implementation.m_texture = texture;
        };

        inline void render() const { m_implementation.render(); };
};

#endif // STATIC_VERTEX_ARRAY_2D_H
