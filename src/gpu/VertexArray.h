/* VertexArray.h */

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "Vertex.h"

template <typename T, size_t N>
class VertexArray {
    private:
        T m_vertices[N];
};

#endif // VERTEX_ARRAY_H

