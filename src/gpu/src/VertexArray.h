/* VertexArray.h - GPU */

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <TargetTypes.h>
#include "Debug.h"
#include <GPUImpl.h>
#include "Vertex.h"
#include "Texture.h"

template <size_t N>
class VertexArray2D {
    public:
        VertexArray2DImpl<N> m_implementation;

    public:
        Vertex2D (&vertices)[N];

        VertexArray2D(TextureID texture) :
                m_implementation(texture),
                vertices(*((Vertex2D(*)[N]) m_implementation.m_vertices)) {
            printd(DebugCategory::GPU_VERTICES, "VertexArray2D<", N,"> constructor");
        };

        inline void move(float x, float y) {
            for (size_t i = 0; i < N; i++) {
                vertices[i].x_add(x);
                vertices[i].y_add(y);
            }
        };

        inline void texture(TextureID texture) {
            printd(DebugCategory::GPU_VERTICES,
                "Replace texture: this=", (void*) this,
                ", previous=", m_implementation.m_texture,
                ", new=", texture);
            m_implementation.m_texture = texture;
        };

        inline void render() const { m_implementation.render(); };
};

#endif // VERTEX_ARRAY_H
