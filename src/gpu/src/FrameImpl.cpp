/* FrameImpl.cpp - GPU */

#include <Frame.h>
#include "VertexArray.h"
#include "FrameImpl.h"

static ColorRGBA to_gpu_color(int color) {
    switch (color) {
        case FrameColors::NORMAL:
            return GPU_WHITE;

        case FrameColors::LIGHT_BLUE:
            return ColorRGBA(0.83984375f, 0.875f, 1.0f, 1.0f);

        case FrameColors::RED:
            return ColorRGBA(1.0, 0.0f, 0.0f, 1.0f);

        default:
            return GPU_WHITE;
    }
}

FrameImpl::FrameImpl(const Frame& frame) :
        m_frame(frame),
        m_vertex_array(TexturesID::FRAME) {
    #ifdef DEBUG
    print("FrameImpl constructor\n");
    #endif

    //const TextureData& data = get_texture_data(TexturesID::FRAME);
    //const gpu_float_t texture_width = 16.0f; // TODO
    const TextureData data(16.0f, 0, 0, 0, 0, 0);

    color(FrameColors::NORMAL);
    resize();

    // Right
    m_vertex_array.vertices[0].u = 0.0f;
    m_vertex_array.vertices[0].v = 0.25f;

    m_vertex_array.vertices[1].u = 0.0f;
    m_vertex_array.vertices[1].v = 1.0f;

    m_vertex_array.vertices[2].u = tile_size / data.width;
    m_vertex_array.vertices[2].v = 1.0f;

    m_vertex_array.vertices[3].u = tile_size / data.width;
    m_vertex_array.vertices[3].v = 0.25f;

    // Top
    m_vertex_array.vertices[4].u = tile_size / data.width;
    m_vertex_array.vertices[4].v = 0.0f;

    m_vertex_array.vertices[5].u = 0.0f;
    m_vertex_array.vertices[5].v = 0.0f;

    m_vertex_array.vertices[6].u = 0.0f;
    m_vertex_array.vertices[6].v = 0.25f;

    m_vertex_array.vertices[7].u = tile_size / data.width;
    m_vertex_array.vertices[7].v = 0.25f;

    // Bottom
    m_vertex_array.vertices[8].u = 0.0f;
    m_vertex_array.vertices[8].v = 0.75f;

    m_vertex_array.vertices[9].u = tile_size / data.width;
    m_vertex_array.vertices[9].v = 0.75f;

    m_vertex_array.vertices[10].u = tile_size / data.width;
    m_vertex_array.vertices[10].v = 1.0f;

    m_vertex_array.vertices[11].u = 0.0f;
    m_vertex_array.vertices[11].v = 1.0f;

    // Left
    m_vertex_array.vertices[12].u = tile_size / data.width;
    m_vertex_array.vertices[12].v = 0.0f;

    m_vertex_array.vertices[13].u = tile_size / data.width;
    m_vertex_array.vertices[13].v = 0.75f;

    m_vertex_array.vertices[14].u = 0.0f;
    m_vertex_array.vertices[14].v = 0.75f;

    m_vertex_array.vertices[15].u = 0.0f;
    m_vertex_array.vertices[15].v = 0.0f;
}

void FrameImpl::color(int color) {
    const ColorRGBA c = to_gpu_color(color);

    for (unsigned int i = 0; i < 16; i++) {
        m_vertex_array.vertices[i].color(c);
    }
}

void FrameImpl::resize() {
    //print("x: %d, y:%d\n", m_frame.position().x, m_frame.position().y);
    const gpu_float_t x = m_frame.position().x;
    const gpu_float_t y = m_frame.position().y;

    const gpu_float_t width = 10; // TODO
    const gpu_float_t height = 22; // TODO

    const gpu_float_t texture_width = 16.0f; // TODO

    // Right
    m_vertex_array.vertices[0].x = x + width * tile_size;
    m_vertex_array.vertices[0].y = y + tile_size * 2.0f;

    m_vertex_array.vertices[1].x = x + width * tile_size;
    m_vertex_array.vertices[1].y = y + height * tile_size;

    m_vertex_array.vertices[2].x = x + (width + 1.0f) * tile_size;
    m_vertex_array.vertices[2].y = y + (height + 1.0f) * tile_size;
    m_vertex_array.vertices[2].u = tile_size / texture_width;

    m_vertex_array.vertices[3].x = x + (width + 1.0f) * tile_size;
    m_vertex_array.vertices[3].y = y + tile_size;
    m_vertex_array.vertices[3].u = tile_size / texture_width;

    // Top
    m_vertex_array.vertices[4].x = x - tile_size;
    m_vertex_array.vertices[4].y = y + tile_size;
    m_vertex_array.vertices[4].u = tile_size / texture_width;

    m_vertex_array.vertices[5].x = x;
    m_vertex_array.vertices[5].y = y + 2.0f * tile_size;

    m_vertex_array.vertices[6].x = x + width * tile_size;
    m_vertex_array.vertices[6].y = y + 2.0f * tile_size;

    m_vertex_array.vertices[7].x = x + (width + 1.0f) * tile_size;
    m_vertex_array.vertices[7].y = y + tile_size;
    m_vertex_array.vertices[7].u = tile_size / texture_width;

    // Bottom
    m_vertex_array.vertices[8].x = x;
    m_vertex_array.vertices[8].y = y + height * tile_size;

    m_vertex_array.vertices[9].x = x - tile_size;
    m_vertex_array.vertices[9].y = y + (height + 1.0f) * tile_size;
    m_vertex_array.vertices[9].u = tile_size / texture_width;
    m_vertex_array.vertices[10].x = x + (width + 1.0f) * tile_size;
    m_vertex_array.vertices[10].y = y + (height + 1.0f) * tile_size;
    m_vertex_array.vertices[10].u = tile_size / texture_width;

    m_vertex_array.vertices[11].x = x + width * tile_size;
    m_vertex_array.vertices[11].y = y + height * tile_size;

    // Left
    m_vertex_array.vertices[12].x = x - tile_size;
    m_vertex_array.vertices[12].y = y + tile_size;
    m_vertex_array.vertices[12].u = tile_size / texture_width;

    m_vertex_array.vertices[13].x = x - tile_size;
    m_vertex_array.vertices[13].y = y + (height + 1.0f) * tile_size;
    m_vertex_array.vertices[13].u = tile_size / texture_width;

    m_vertex_array.vertices[14].x = x;
    m_vertex_array.vertices[14].y = y + height * tile_size;

    m_vertex_array.vertices[15].x = x;
    m_vertex_array.vertices[15].y = y + 2.0f * tile_size;
}
