/* Image.cpp - GPU */

#include <Debug.h>
#include "Rect.h"
#include "Image.h"

Image::Image(
    const Point2D& coords,
    const Size2D& size,
    const TextureID& texture) :
        m_rect(
            coords,
            size,
            GPU_TOP_LEFT, GPU_WHITE,
            GPU_TOP_RIGHT, GPU_WHITE,
            GPU_BOTTOM_LEFT, GPU_WHITE,
            GPU_BOTTOM_RIGHT, GPU_WHITE,
            texture) {
    printd("Image constructor: " << texture);
}
