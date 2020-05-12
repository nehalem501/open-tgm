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
            /*glBegin(GL_QUADS);
            glColor3f(1, 0, 0);
            glVertex2f(10, 10);
            glColor3f(0, 1, 0);
            glVertex2f(100, 10);
            glColor3f(0, 0, 1);
            glVertex2f(100,  100);
            glColor3f(1, 0, 1);
            glVertex2f(10, 100);
            glEnd();*/

            glBegin(GL_QUADS);

            for (unsigned int i = 0; i < N; i++) {
                glColor4f(
                    m_vertices[i].r,
                    m_vertices[i].g,
                    m_vertices[i].b,
                    m_vertices[i].a);

                glVertex2f(m_vertices[i].x, m_vertices[i].y);
            }

            glEnd();
        };
};

#endif // GPU_IMPL_OPENGL_H
