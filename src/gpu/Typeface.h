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
            //
        };

    private:
        //Position m_position;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // TYPEFACE_H
