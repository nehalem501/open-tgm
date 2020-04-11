/* GPUImpl.h - dummy_gpu */

#ifndef GPU_IMPL_DUMMY_GPU_H
#define GPU_IMPL_DUMMY_GPU_H

#include <stddef.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

template <size_t N>
class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
        };

        void render() const {
        };
};

#endif // GPU_IMPL_DUMMY_GPU_H
