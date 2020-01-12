/* Rect.cpp - GPU */

#include "Rect.h"

Rect::Rect(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    Texture *texture) :
        m_position(0, 0),
        m_vertex_array(texture) {
    #ifdef DEBUG
    print("Rect constructor: %s\n", m_name);
    #endif

    m_vertex_array.vertices[0] = { x, y,  0, 0,  1, 1, 1, 1};
    m_vertex_array.vertices[1] = { x, y + height,  0, 0,  1, 1, 1, 1};
    m_vertex_array.vertices[2] = { x + width, y + height,  0, 0,  1, 1, 1, 1};
    m_vertex_array.vertices[3] = { x + width, y,  0, 0,  1, 1, 1, 1};
}

void Rect::render() const {
    m_vertex_array.render();
}
