/* GPUImpl.h - Deko3D */

#ifndef GPU_IMPL_DEKO3D_H
#define GPU_IMPL_DEKO3D_H

#include <stddef.h>
#include <Global.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    // TODO
    return Size2D(screen.width, screen.height);
}

template <size_t N>
class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
            m_vertices = new Vertex2D[N];
        };

        void render() const {
        };
};

#endif // GPU_IMPL_DEKO3D_H
