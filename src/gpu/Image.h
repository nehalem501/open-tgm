/* Image.h - GPU */

#ifndef IMAGE_H
#define IMAGE_H

#include <Position.h>
#include "Vertex.h"
#include "Texture.h"
#include "Rect.h"

class Image {
    public:
        Image(
            gpu_float_t x,
            gpu_float_t y,
            gpu_float_t width,
            gpu_float_t height,
            TextureID texture);

        inline void texture(TextureID texture) { m_rect.texture(texture); };

        inline void move(gpu_float_t x, gpu_float_t y) { m_rect.move(x, y); };

        inline void position(gpu_float_t x, gpu_float_t y) {
            m_rect.position(x, y);
        };

        inline void size(gpu_float_t width, gpu_float_t height) {
            m_rect.size(width, height);
        };

        inline void render() const { m_rect.render(); };

    private:
        Rect m_rect;
};

#endif // RECT_H
