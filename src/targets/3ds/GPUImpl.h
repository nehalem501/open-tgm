/* Global3DS.h - 3DS */

#ifndef GPU_IMPL_3DS_H
#define GPU_IMPL_3DS_H

#include <stddef.h>
#include "lib3ds.h"
#include <Vertex.h>
#include <Texture.h>

extern C3D_Tex empty_tex;

template <size_t N>
struct VertexArray2DImpl {
    Texture *m_texture;
    Vertex2D *m_vertices;

    VertexArray2DImpl(Texture *texture) : m_texture(texture) {
        m_vertices = (Vertex2D*) linearAlloc(sizeof(Vertex2D) * N);
        memset(m_vertices, 0, sizeof(Vertex2D) * N);
    };

    void render() const {
        C3D_TexBind(0, &empty_tex);

        C3D_BufInfo *info = C3D_GetBufInfo();
        BufInfo_Init(info);
	    BufInfo_Add(info, m_vertices, sizeof(Vertex2D), 3, 0x210);
        C3D_SetBufInfo(info);

        C3D_DrawArrays(GPU_TRIANGLE_STRIP, 0, N);

        /*C3D_ImmDrawBegin(GPU_TRIANGLE_STRIP);
        //C3D_ImmDrawBegin(GPU_TRIANGLES);

        for (unsigned int i = 0; i < N; i++) {
            C3D_ImmSendAttrib(m_vertices[i].x, m_vertices[i].y, 0.5f, 0.0f);
            C3D_ImmSendAttrib(m_vertices[i].u, m_vertices[i].v, 0.0f, 0.0f);
            C3D_ImmSendAttrib(m_vertices[i].r, m_vertices[i].r, m_vertices[i].b, m_vertices[i].a);
        }

        C3D_ImmDrawEnd();*/
    };
};

#endif // GPU_IMPL_3DS_H
