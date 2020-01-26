/* Image.cpp - GPU */

#include "Rect.h"
#include "Image.h"

Image::Image(
    gpu_float_t x,
    gpu_float_t y,
    gpu_float_t width,
    gpu_float_t height,
    Texture *texture) :
        m_rect(
            x, y, width, height,
            GPU_WHITE, GPU_WHITE, GPU_WHITE, GPU_WHITE,
            texture) {
    #ifdef DEBUG
    print("Image constructor: %s\n", m_name);
    #endif
}
