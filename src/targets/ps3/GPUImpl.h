/* GPUImpl.h - PS3 */

#ifndef GPU_IMPL_PS3_H
#define GPU_IMPL_PS3_H

#include <stddef.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    return Size2D(320, 240);
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

#endif // GPU_IMPL_PS3_H
