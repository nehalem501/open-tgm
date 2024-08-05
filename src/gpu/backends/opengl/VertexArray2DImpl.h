/* VertexArray2DImpl.h - OpenGL */

#ifndef VERTEX_ARRAY_2D_IMPL_OPENGL_H
#define VERTEX_ARRAY_2D_IMPL_OPENGL_H

#include <stddef.h>
#include <GPU.h>
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
            glBindTexture(GL_TEXTURE_2D, GPU::get_current().get_texture(m_texture).handle());

            glBegin(GL_QUADS);

            for (unsigned int i = 0; i < N; i++) {
                glColor4f(
                    m_vertices[i].r(),
                    m_vertices[i].g(),
                    m_vertices[i].b(),
                    m_vertices[i].a());

                glTexCoord2f(m_vertices[i].u(), m_vertices[i].v());
                glVertex2f(m_vertices[i].x(), m_vertices[i].y());
            }

            glEnd();
        };
};

#endif // VERTEX_ARRAY_2D_IMPL_OPENGL_H
