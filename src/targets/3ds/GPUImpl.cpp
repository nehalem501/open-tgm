/* GPUImpl.h - 3DS */

#ifndef GPUIMPL_3DS_H
#define GPUIMPL_3DS_H

#include <citro3d.h>
#include "../../gpu/VertexArray.h"

extern C3D_Tex empty_tex;

void render_vertices_2d(const Vertex2D *vertices, unsigned int length) {
    C3D_TexBind(0, &empty_tex);
    C3D_ImmDrawBegin(GPU_TRIANGLE_STRIP);

    for (unsigned int i = 0; i < length; i++) {
        C3D_ImmSendAttrib(vertices[i].x, vertices[i].y, 0.5f, 0.0f);
        C3D_ImmSendAttrib(vertices[i].u, vertices[i].v, 0.0f, 0.0f);
        C3D_ImmSendAttrib(vertices[i].r, vertices[i].r, vertices[i].b, vertices[i].a);
    }

    C3D_ImmDrawEnd();
}

#endif // GPUIMPL_3DS_H
