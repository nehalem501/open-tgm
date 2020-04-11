/* BackgroundImpl.cpp - GPU */

#include "Texture.h"
#include "BackgroundImpl.h"

BackgroundImpl::BackgroundImpl() :
        m_background_gradient(
            Vector2D(0, 0),
            100, 200,
            GPU_TOP_LEFT, GPU_BLUE,
            GPU_TOP_RIGHT, GPU_BLUE,
            GPU_BOTTOM_LEFT, GPU_BLACK,
            GPU_BOTTOM_RIGHT, GPU_BLACK,
            TexturesID::NONE),
        m_background_image(Vector2D(10, 10), 100, 200, TexturesID::BACKGROUND) {
    #ifdef DEBUG
    print("BackgroundImpl constructor\n");
    #endif
}

void BackgroundImpl::render(const bool options) const {
    if (options) { }
        // Draw settings background
        m_background_gradient.render();/*
    } else {*/
        // Draw game background
        m_background_image.render();/*
    }*/
}
