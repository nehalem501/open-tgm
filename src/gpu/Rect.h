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
            ColorRGBA top_left,
            ColorRGBA top_right,
            ColorRGBA bottom_left,
            ColorRGBA bottom_right,
            Texture *texture);

        inline void texture(Texture *texture) {
            m_vertex_array.texture(texture);
        };

        inline void move(gpu_float_t x, gpu_float_t y) {
            for (unsigned int i = 0; i < 4; i++) {
                m_vertex_array.vertices[i].x += x;
                m_vertex_array.vertices[i].y += y;
            }
        };

        inline void position(gpu_float_t x, gpu_float_t y) {
            move(x - top_left().x, y - top_left().y);
        };

        inline void size(gpu_float_t width, gpu_float_t height) {
            top_right().x = top_left().x + width;
            bottom_left().y = top_right().y + height;
            bottom_right().x = top_left().x + width;
            bottom_right().y = top_left().y + height;
        };

        inline Vertex2D& top_left() { return m_vertex_array.vertices[0]; };
        inline Vertex2D& top_right() { return m_vertex_array.vertices[3]; };
        inline Vertex2D& bottom_left() { return m_vertex_array.vertices[1]; };
        inline Vertex2D& bottom_right() { return m_vertex_array.vertices[2]; };

        void render() const;

    private:
        VertexArray2D<4> m_vertex_array;
};

#endif // RECT_H
