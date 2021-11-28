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
            const Point2D& coords,
            const Size2D& size,
            const TextureID& texture);

        inline void texture(TextureID texture) { m_rect.texture(texture); };

        inline void move(float x, float y) { m_rect.move(x, y); };

        inline void position(float x, float y) {
            m_rect.position(x, y);
        };

        inline void size(float width, float height) {
            m_rect.size(width, height);
        };

        inline void render() const { m_rect.render(); };

    private:
        Rect m_rect;
};

#endif // IMAGE_H
