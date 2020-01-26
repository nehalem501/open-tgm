/* GPUImpl.h - 3DS */

#ifndef GPU_IMPL_3DS_H
#define GPU_IMPL_3DS_H

#include <stddef.h>
#include "lib3ds.h"
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

#define INDICES_LEN (N + N / 2)

C3D_Tex* get_texture(TextureID id);

template <size_t N>
class VertexArray2DImpl {
    private:
        //;

    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
            m_vertices = (Vertex2D*) linearAlloc(sizeof(Vertex2D) * N);
            memset(m_vertices, 0, sizeof(Vertex2D) * N);

            m_indices = (gpu_indices_t*) linearAlloc(
                sizeof(gpu_indices_t) * INDICES_LEN);

            const gpu_indices_t quad_indices[] = { 0, 1, 2, 2, 3, 0 };
            for (unsigned int i = 0; i < INDICES_LEN; i += 6) {
                m_indices[i] = quad_indices[0];
                m_indices[i + 1] = quad_indices[1];
                m_indices[i + 2] = quad_indices[2];
                m_indices[i + 3] = quad_indices[3];
                m_indices[i + 4] = quad_indices[4];
                m_indices[i + 5] = quad_indices[5];
            }
        };

        void render() const {
            C3D_TexBind(0, get_texture(m_texture));

            /*C3D_BufInfo *info = C3D_GetBufInfo();
            BufInfo_Init(info);
	        BufInfo_Add(info, m_vertices, sizeof(Vertex2D), 3, 0x210);
            C3D_SetBufInfo(info);

            C3D_DrawArrays(GPU_TRIANGLE_STRIP, 0, N);*/

            C3D_BufInfo *info = C3D_GetBufInfo();
            BufInfo_Init(info);
	        BufInfo_Add(info, m_vertices, sizeof(Vertex2D), 3, 0x210);
            C3D_SetBufInfo(info);

            C3D_DrawElements(
                GPU_TRIANGLES,
                INDICES_LEN,
                C3D_UNSIGNED_SHORT,
                m_indices);
        };
};

#endif // GPU_IMPL_3DS_H
