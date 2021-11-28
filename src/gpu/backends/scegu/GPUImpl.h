/* GPUImpl.h - SCEGU */

#ifndef GPU_IMPL_SCEGU_H
#define GPU_IMPL_SCEGU_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <pspsdk.h>
#include "GPUTypes.h"
#include <Vertex.h>
#include <Texture.h>

inline Size2D screen_size() {
    return Size2D(480, 272);
}

#define INDICES_LEN (N + N / 2)

template <size_t N>
class VertexArray2DImpl {
    public:
        Vertex2D *m_vertices;
        gpu_indices_t *m_indices;
        TextureID m_texture;

        VertexArray2DImpl(TextureID texture) : m_texture(texture) {
            m_vertices = (Vertex2D*) malloc(N * sizeof(Vertex2D));
            memset((void*) m_vertices, 0, N * sizeof(Vertex2D));

            m_indices = (gpu_indices_t*) malloc(sizeof(gpu_indices_t) * INDICES_LEN);

            //const gpu_indices_t quad_indices[] = { 0, 1, 2, 2, 3, 0 };
            const gpu_indices_t quad_indices[] = { 0, 1, 2, 0, 2, 3 };
            for (unsigned int i = 0; i < INDICES_LEN; i += 6) {
                m_indices[i] = quad_indices[0] + (i / 6) * 4;
                m_indices[i + 1] = quad_indices[1] + (i / 6) * 4;
                m_indices[i + 2] = quad_indices[2] + (i / 6) * 4;
                m_indices[i + 3] = quad_indices[3] + (i / 6) * 4;
                m_indices[i + 4] = quad_indices[4] + (i / 6) * 4;
                m_indices[i + 5] = quad_indices[5] + (i / 6) * 4;
            }
        };

        void render() const {
            const Texture& texture = get_texture(m_texture);

            sceGuTexMode(texture.handle.format, 0, 0, texture.handle.swizzled);
            sceGuTexImage(0, texture.width, texture.height, texture.width, texture.handle.data);

            sceGumDrawArray(
                GU_TRIANGLES,
                GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_INDEX_16BIT,
                INDICES_LEN,
                m_indices,
                m_vertices);
        };
};

#endif // GPU_IMPL_SCEGU_H
