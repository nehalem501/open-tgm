/* VertexArray.h - GPU */

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <GPUImpl.h>
#include "Vertex.h"
#include "Texture.h"

template <size_t N>
class VertexArray2D {
    public:
        VertexArray2DImpl<N> m_implementation;

    public:
        Vertex2D (&vertices)[N];

        VertexArray2D(Texture *texture) :
                m_implementation(texture),
                vertices(*((Vertex2D(*)[N]) m_implementation.m_vertices)) {
            #ifdef DEBUG
            print("VertexArray2D<%d> constructor\n", (int) N);
            #endif
        };

        inline void render() const { m_implementation.render(); };
};

#endif // VERTEX_ARRAY_H
