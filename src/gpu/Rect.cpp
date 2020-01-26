/* Rect.cpp - GPU */

#include "Rect.h"

Rect::Rect(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    TexCoord top_left_tex_coords,
    ColorRGBA top_left_color,
    TexCoord top_right_tex_coords,
    ColorRGBA top_right_color,
    TexCoord bottom_left_tex_coords,
    ColorRGBA bottom_left_color,
    TexCoord bottom_right_tex_coords,
    ColorRGBA bottom_right_color,
    TextureID texture) :
        m_vertex_array(texture) {
    #ifdef DEBUG
    print("Rect constructor: %s\n", m_name);
    #endif

    m_vertex_array.vertices[0] = {
        x, y,
        top_left_tex_coords.u, top_left_tex_coords.v,
        top_left_color.r,
        top_left_color.g,
        top_left_color.b,
        top_left_color.a };
    m_vertex_array.vertices[1] = {
        x, y + height,
        bottom_left_tex_coords.u, bottom_left_tex_coords.v,
        bottom_left_color.r,
        bottom_left_color.g,
        bottom_left_color.b,
        bottom_left_color.a };
    m_vertex_array.vertices[2] = {
        x + width, y + height,
        bottom_right_tex_coords.u,
        bottom_right_tex_coords.v,
        bottom_right_color.r,
        bottom_right_color.g,
        bottom_right_color.b,
        bottom_right_color.a };
    m_vertex_array.vertices[3] = {
        x + width, y,
        top_right_tex_coords.u,
        top_right_tex_coords.v,
        top_right_color.r,
        top_right_color.g,
        top_right_color.b,
        top_right_color.a };
}

void Rect::render() const {
    m_vertex_array.render();
}
