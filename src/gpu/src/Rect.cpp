/* Rect.cpp - GPU */

#include <Debug.h>
#include "Rect.h"

Rect::Rect(
    const Point2D& coords,
    const Size2D& size,
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
    printd("Rect constructor: " << texture);

    m_vertex_array.vertices[0] = Vertex2D(
        coords,
        top_left_tex_coords,
        top_left_color);
    m_vertex_array.vertices[1] = Vertex2D(
        Point2D(coords.x(), coords.y() + size.height()),
        bottom_left_tex_coords,
        bottom_left_color);
    m_vertex_array.vertices[2] = Vertex2D(
        Point2D(coords.x() + size.width(), coords.y() + size.height()),
        bottom_right_tex_coords,
        bottom_right_color);
    m_vertex_array.vertices[3] = Vertex2D(
        Point2D(coords.x() + size.width(), coords.y()),
        top_right_tex_coords,
        top_right_color);
}

Rect::Rect(
    const Point2D& coords,
    const Size2D& size,
    const ColorRGBA& color) :
        m_vertex_array(TexturesID::NONE)
{
    printd("Rect constructor: No texture");

    m_vertex_array.vertices[0] = Vertex2D(
        coords,
        TexCoord(0, 0),
        color);
    m_vertex_array.vertices[1] = Vertex2D(
        Point2D(coords.x(), coords.y() + size.height()),
        TexCoord(0, 0),
        color);
    m_vertex_array.vertices[2] = Vertex2D(
        Point2D(coords.x() + size.width(), coords.y() + size.height()),
        TexCoord(0, 0),
        color);
    m_vertex_array.vertices[3] = Vertex2D(
        Point2D(coords.x() + size.width(), coords.y()),
        TexCoord(0, 0),
        color);
}
