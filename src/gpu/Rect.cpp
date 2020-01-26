/* Rect.cpp - GPU */

#include "Rect.h"

Rect::Rect(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    ColorRGBA top_left,
    ColorRGBA top_right,
    ColorRGBA bottom_left,
    ColorRGBA bottom_right,
    Texture *texture) :
        m_vertex_array(texture) {
    #ifdef DEBUG
    print("Rect constructor: %s\n", m_name);
    #endif

    m_vertex_array.vertices[0] = {
        x, y,
        0, 0,
        top_left.r, top_left.g, top_left.b, top_left.a };
    m_vertex_array.vertices[1] = {
        x, y + height,
        0, 0,
        bottom_left.r, bottom_left.g, bottom_left.b, bottom_left.a };
    m_vertex_array.vertices[2] = {
        x + width, y + height,
        0, 0,
        bottom_right.r, bottom_right.g, bottom_right.b, bottom_right.a };
    m_vertex_array.vertices[3] = {
        x + width, y,
        0, 0,
        top_right.r, top_right.g, top_right.b, top_right.a };
}

void Rect::render() const {
    m_vertex_array.render();
}
