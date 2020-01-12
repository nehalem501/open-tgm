/* Rect.h - GPU */

#ifndef RECT_H
#define RECT_H

#include <Position.h>
#include "Vertex.h"
#include "Texture.h"
#include "VertexArray.h"

class Rect {
    public:
        Rect(
            gpu_float_t x,
            gpu_float_t y,
            gpu_float_t width,
            gpu_float_t height,
            Texture *texture);

        inline void texture(Texture *texture) {
            m_vertex_array.texture(texture);
        };

        inline Vertex2D& top_left() { return m_vertex_array.vertices[0]; };
        inline Vertex2D& top_right() { return m_vertex_array.vertices[3]; };
        inline Vertex2D& bottom_left() { return m_vertex_array.vertices[1]; };
        inline Vertex2D& bottom_right() { return m_vertex_array.vertices[2]; };

        void render() const;

    private:
        Position m_position;
        VertexArray2D<4> m_vertex_array;
};

#endif // RECT_H
