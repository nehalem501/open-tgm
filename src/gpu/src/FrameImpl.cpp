/* FrameImpl.cpp - GPU */

#include <Debug.h>
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
        m_background(Point2D(0, 0), Size2D(0, 0), ColorRGBA(0, 0, 0, 0.8f)),
        m_vertex_array(TexturesID::FRAME) {
    printd("FrameImpl constructor");

    register_reloadable(this);

    color(FrameColors::NORMAL);
    resize();
}

void FrameImpl::color(int color) {
    const ColorRGBA c = to_gpu_color(color);

    for (unsigned int i = 0; i < 16; i++) {
        m_vertex_array.vertices[i].color(c);
    }
}

void FrameImpl::texcoords(const TextureData& data) {
    //int a = data2.height;
    //a++;
    //const TextureData data(16, 64, 0, 0, 8, 64);

    // Right
    m_vertex_array.vertices[0].tex_coords(data.tex_coord_top_left /*+ TexCoord(0.f, 0.25f)*/);
    m_vertex_array.vertices[1].tex_coords(data.tex_coord_bottom_left);
    m_vertex_array.vertices[2].tex_coords(data.tex_coord_bottom_right);
    m_vertex_array.vertices[3].tex_coords(data.tex_coord_top_right /*+ TexCoord(0.f, 0.25f)*/);

    // Top
    m_vertex_array.vertices[4].tex_coords(data.tex_coord_top_right);
    m_vertex_array.vertices[5].tex_coords(data.tex_coord_top_left);
    m_vertex_array.vertices[6].tex_coords(data.tex_coord_top_left /*+ TexCoord(0.f, 0.25f)*/);
    m_vertex_array.vertices[7].tex_coords(data.tex_coord_top_right /*+ TexCoord(0.f, 0.25f)*/);

    // Bottom
    m_vertex_array.vertices[8].tex_coords(data.tex_coord_bottom_right /*+ TexCoord(0.f, -0.25f)*/);
    m_vertex_array.vertices[9].tex_coords(data.tex_coord_bottom_left /*+ TexCoord(0.f, -0.25f)*/);
    m_vertex_array.vertices[10].tex_coords(data.tex_coord_bottom_left);
    m_vertex_array.vertices[11].tex_coords(data.tex_coord_bottom_right);

    // Left
    m_vertex_array.vertices[12].tex_coords(data.tex_coord_top_left);
    m_vertex_array.vertices[13].tex_coords(data.tex_coord_bottom_left /*+ TexCoord(0.f, -0.25f)*/);
    m_vertex_array.vertices[14].tex_coords(data.tex_coord_bottom_right /*+ TexCoord(0.f, -0.25f)*/);
    m_vertex_array.vertices[15].tex_coords(data.tex_coord_top_right);
}

void FrameImpl::resize() {
    texcoords(get_texture_data(TexturesID::FRAME));

    const float x = m_frame.position().x; // TODO
    const float y = m_frame.position().y;

    const float width = 10; // TODO
    const float height = 22; // TODO

    const float gpu_tile_size = tile_size;

    m_background.position(x, y + gpu_tile_size * 2);
    m_background.size(width * gpu_tile_size, (height - 2) * gpu_tile_size);

    // Right
    m_vertex_array.vertices[0].x(x + width * gpu_tile_size);
    m_vertex_array.vertices[0].y(y + gpu_tile_size * 2.0f);

    m_vertex_array.vertices[1].x(x + width * gpu_tile_size);
    m_vertex_array.vertices[1].y(y + height * gpu_tile_size);

    m_vertex_array.vertices[2].x(m_vertex_array.vertices[0].x() + gpu_tile_size);
    m_vertex_array.vertices[2].y(y + (height + 1.0f) * gpu_tile_size);

    m_vertex_array.vertices[3].x(m_vertex_array.vertices[2].x());
    m_vertex_array.vertices[3].y(y + gpu_tile_size);

    // Top
    m_vertex_array.vertices[4].x(x - gpu_tile_size);
    m_vertex_array.vertices[4].y(y + gpu_tile_size);

    m_vertex_array.vertices[5].x(x);
    m_vertex_array.vertices[5].y(y + 2.0f * gpu_tile_size);

    m_vertex_array.vertices[6].x(x + width * gpu_tile_size);
    m_vertex_array.vertices[6].y(y + 2.0f * gpu_tile_size);

    m_vertex_array.vertices[7].x(x + (width + 1.0f) * gpu_tile_size);
    m_vertex_array.vertices[7].y(y + gpu_tile_size);

    // Bottom
    m_vertex_array.vertices[8].x(x);
    m_vertex_array.vertices[8].y(y + height * gpu_tile_size);

    m_vertex_array.vertices[9].x(x - gpu_tile_size);
    m_vertex_array.vertices[9].y(y + (height + 1.0f) * gpu_tile_size);

    m_vertex_array.vertices[10].x(x + (width + 1.0f) * gpu_tile_size);
    m_vertex_array.vertices[10].y(y + (height + 1.0f) * gpu_tile_size);

    m_vertex_array.vertices[11].x(x + width * gpu_tile_size);
    m_vertex_array.vertices[11].y(y + height * gpu_tile_size);

    // Left
    m_vertex_array.vertices[12].x(x - gpu_tile_size);
    m_vertex_array.vertices[12].y(y + gpu_tile_size);

    m_vertex_array.vertices[13].x(x - gpu_tile_size);
    m_vertex_array.vertices[13].y(y + (height + 1.0f) * gpu_tile_size);

    m_vertex_array.vertices[14].x(x);
    m_vertex_array.vertices[14].y(y + height * gpu_tile_size);

    m_vertex_array.vertices[15].x(x);
    m_vertex_array.vertices[15].y(y + 2.0f * gpu_tile_size);
}
