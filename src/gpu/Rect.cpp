/* Rect.cpp - GPU */

#include "Rect.h"

Rect::Rect(
    Vector2D coords,
    gpu_float_t width,
    gpu_float_t height,
    const TexCoord& top_left_tex_coords,
    const ColorRGBA& top_left_color,
    const TexCoord& top_right_tex_coords,
    const ColorRGBA& top_right_color,
    const TexCoord& bottom_left_tex_coords,
    const ColorRGBA& bottom_left_color,
    const TexCoord& bottom_right_tex_coords,
    const ColorRGBA bottom_right_color,
    TextureID texture) :
        m_vertex_array(texture) {
    #ifdef DEBUG
    print("Rect constructor: %s\n", m_name);
    #endif

    m_vertex_array.vertices[0] = Vertex2D(
        coords,
        top_left_tex_coords,
        top_left_color);
    m_vertex_array.vertices[1] = Vertex2D(
        Vector2D(coords.x, coords.y + height),
        bottom_left_tex_coords,
        bottom_left_color);
    m_vertex_array.vertices[2] = Vertex2D(
        Vector2D(coords.x + width, coords.y + height),
        bottom_right_tex_coords,
        bottom_right_color);
    m_vertex_array.vertices[3] = Vertex2D(
        Vector2D(coords.x + width, coords.y),
        top_right_tex_coords,
        top_right_color);
}

void Rect::render() const {
    m_vertex_array.render();
}
