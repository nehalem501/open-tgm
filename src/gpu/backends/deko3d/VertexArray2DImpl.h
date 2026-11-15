/* VertexArray2DImpl.h - Deko3D */

#ifndef VERTEX_ARRAY_2D_IMPL_DEKO3D_H
#define VERTEX_ARRAY_2D_IMPL_DEKO3D_H

#include <stddef.h>
#include <Global.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    // TODO
    return Size2D(screen.width, screen.height);
}

class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;
        size_t m_size;

        VertexArray2DImpl(TextureID texture, size_t size) : m_texture(texture), m_size(size) {
            m_vertices = new Vertex2D[m_size];
        };

        void render() const {
        };
};

#endif // VERTEX_ARRAY_2D_IMPL_DEKO3D_H
