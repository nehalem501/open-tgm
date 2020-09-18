/* BackgroundImpl.cpp - GPU */

#include <Global.h>
#include <GPUImpl.h>
#include "Texture.h"
#include "BackgroundImpl.h"

BackgroundImpl::BackgroundImpl() :
        m_background_gradient(
            Point2D(0, 0),
            Size2D(screen.width, screen.height),
            GPU_TOP_LEFT, GPU_BLUE,
            GPU_TOP_RIGHT, GPU_BLUE,
            GPU_BOTTOM_LEFT, GPU_BLACK,
            GPU_BOTTOM_RIGHT, GPU_BLACK,
            TexturesID::NONE),
        m_background_image(
            Point2D(0, 0),
            Size2D(screen.width, screen.height), // TODO aspect ratio & texture size
            TexturesID::BACKGROUND) {
    #ifdef DEBUG
    print("BackgroundImpl constructor\n");
    #endif
}

void BackgroundImpl::render(const bool options) const {
    if (options) {
        // Draw settings background
        m_background_gradient.render();
    } else {
        // Draw game background
        //m_background_image.render();
    }
}
