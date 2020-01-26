/* Image.cpp - GPU */

#include "Rect.h"
#include "Image.h"

Image::Image(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    TextureID texture) :
        m_rect(
            x, y, width, height,
            TOP_LEFT, GPU_WHITE,
            TOP_RIGHT, GPU_WHITE,
            BOTTOM_LEFT, GPU_WHITE,
            BOTTOM_RIGHT, GPU_WHITE,
            texture) {
    #ifdef DEBUG
    print("Image constructor: %s\n", m_name);
    #endif
}
