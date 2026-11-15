/* VertexArray2DImpl.h - OpenGL3 */

#ifndef VERTEX_ARRAY_2D_IMPL_OPENGL3_H
#define VERTEX_ARRAY_2D_IMPL_OPENGL3_H

#include <stddef.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;
        size_t m_size;

        VertexArray2DImpl(TextureID texture, size_t size) : m_texture(texture), m_size(size) {
            m_vertices = new Vertex2D[size];
        };

        void render() const {
        };
};

#endif // VERTEX_ARRAY_2D_IMPL_OPENGL3_H
