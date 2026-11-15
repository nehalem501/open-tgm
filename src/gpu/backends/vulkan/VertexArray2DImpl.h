/* GPUImpl.h - Vulkan */

#ifndef GPU_IMPL_DUMMY_GPU_H
#define GPU_IMPL_DUMMY_GPU_H

#include <stddef.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    return Size2D(320, 240);
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

#endif // GPU_IMPL_DUMMY_GPU_H
