/* VertexArray.h - GPU */

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "Vertex.h"
#include "Texture.h"

void render_vertices_2d(const Vertex2D *vertices, unsigned int length);

template <size_t N>
class VertexArray2D {
    public:
        VertexArray2D(Texture *texture) : m_texture(texture) { memset(m_vertices, 0, sizeof(m_vertices)); };
        inline void render() const { render_vertices_2d(m_vertices, N); };

    private:
        Texture *m_texture;
    public: // TODO
        Vertex2D m_vertices[N];
};

/*template <size_t N>
class VertexArray3D {
    private:
        Vertex3D m_vertices[N];
};*/

#endif // VERTEX_ARRAY_H
