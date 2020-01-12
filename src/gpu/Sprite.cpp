/* Sprite.cpp - GPU */

#include "Sprite.h"

Sprite::Sprite(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    Texture *texture) :
        m_position(0, 0),
        m_vertex_array(texture) {
    #ifdef DEBUG
    print("Sprite constructor: %s\n", m_name);
    #endif

    m_vertex_array.vertices[0] = { x, y,  0, 0,  1, 1, 1, 1};
    m_vertex_array.vertices[1] = { x, y + height,  0, 0,  1, 1, 1, 1};
    m_vertex_array.vertices[2] = { x + width, y,  0, 0,  1, 0, 1, 1};
    m_vertex_array.vertices[3] = { x + width, y + height,  0, 0,  1, 1, 1, 1};

    // Should fail !
    //m_vertex_array.m_implementation.m_vertices[4] = { 100, 100,  0, 0,  1, 1, 1, 1};
    //m_vertex_array.vertices[4] = { 100, 100,  0, 0,  1, 1, 1, 1};
}

void Sprite::render() const {
    m_vertex_array.render();
}
