/* Image.cpp - GPU */

#include "Rect.h"
#include "Image.h"

Image::Image(
    Vector2D coords,
    gpu_float_t width,
    gpu_float_t height,
    TextureID texture) :
        m_rect(
            coords,
            width, height,
            GPU_TOP_LEFT, GPU_WHITE,
            GPU_TOP_RIGHT, GPU_WHITE,
            GPU_BOTTOM_LEFT, GPU_WHITE,
            GPU_BOTTOM_RIGHT, GPU_WHITE,
            texture) {
    #ifdef DEBUG
    print("Image constructor: %s\n", m_name);
    #endif
}
