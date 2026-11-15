/* VertexArray2DImpl.h - OpenGL */

#ifndef VERTEX_ARRAY_2D_IMPL_OPENGL_H
#define VERTEX_ARRAY_2D_IMPL_OPENGL_H

#include <stddef.h>
#include <GPU.h>
#include <Vertex.h>
#include <Texture.h>

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
            glBindTexture(GL_TEXTURE_2D, GPU::get_current().get_texture(m_texture).handle());

            glBegin(GL_QUADS);

            for (size_t i = 0; i < m_size; i++) {
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
