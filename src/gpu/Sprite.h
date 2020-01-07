/* Sprite.h - GPU */

#ifndef SPRITE_H
#define SPRITE_H

#include <Position.h>
#include "Texture.h"
#include "VertexArray.h"

class Sprite {
    public:
        Sprite(
            gpu_float_t x,
            gpu_float_t y,
            gpu_float_t width,
            gpu_float_t height,
            Texture *texture);
        
        void render() const;

    private:
        Position m_position;
        VertexArray2D<4> m_vertex_array;
};

#endif // SPRITE_H
