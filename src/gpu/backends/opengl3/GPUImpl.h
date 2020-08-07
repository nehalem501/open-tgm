/* GPUImpl.h - OpenGL3 */

#ifndef GPU_IMPL_OPENGL3_H
#define GPU_IMPL_OPENGL3_H

#include <stddef.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

template <size_t N>
class VertexArray2DImpl {
    private:
        Vertex2D m_vertices_priv[N];
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
            m_vertices = m_vertices_priv;
        };

        void render() const {
        };
};

#endif // GPU_IMPL_OPENGL3_H
