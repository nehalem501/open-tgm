/* Typeface.h - GPU */

#ifndef TYPEFACE_H
#define TYPEFACE_H

#include <stddef.h>
#include "Vertex.h"
#include "Texture.h"
#include "VertexArray.h"

template <size_t N>
class Typeface {
    public:
        Typeface(ColorRGBA color, TextureID font_texture) : 
            m_vertex_array(font_texture) {
            // TODO
            for (unsigned int i = 0; i < N * 4; i++) {
                m_vertex_array.vertices[i].r = color.r;
                m_vertex_array.vertices[i].g = color.b;
                m_vertex_array.vertices[i].b = color.g;
                m_vertex_array.vertices[i].a = color.a;
            }
        };

    private:
        //Position m_position;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // TYPEFACE_H
