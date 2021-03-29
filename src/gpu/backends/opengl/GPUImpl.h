/* GPUImpl.h - OpenGL */

#ifndef GPU_IMPL_OPENGL_H
#define GPU_IMPL_OPENGL_H

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
            glBindTexture(GL_TEXTURE_2D, get_texture(m_texture));

            glBegin(GL_QUADS);

            for (unsigned int i = 0; i < N; i++) {
                glColor4f(
                    m_vertices[i].r,
                    m_vertices[i].g,
                    m_vertices[i].b,
                    m_vertices[i].a);

                glTexCoord2f(m_vertices[i].u, m_vertices[i].v);
                glVertex2f(m_vertices[i].x + 0.5f, m_vertices[i].y + 0.5f);
            }

            glEnd();
        };
};

#endif // GPU_IMPL_OPENGL_H
