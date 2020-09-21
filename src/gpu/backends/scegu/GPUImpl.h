/* GPUImpl.h - SCEGU */

#ifndef GPU_IMPL_SCEGU_H
#define GPU_IMPL_SCEGU_H

#include <stddef.h>
#include <stdlib.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    return Size2D(480, 272);
}

template <size_t N>
class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
            m_vertices = (Vertex2D*) malloc(N * sizeof(Vertex2D));
        };

        void render() const {
        };
};

#endif // GPU_IMPL_SCEGU_H
