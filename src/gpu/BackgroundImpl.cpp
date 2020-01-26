/* BackgroundImpl.cpp - GPU */

#include "Texture.h"
#include "BackgroundImpl.h"

BackgroundImpl::BackgroundImpl() :
        m_background_gradient(
            0, 0, 100, 200,
            TOP_LEFT, GPU_BLUE,
            TOP_RIGHT, GPU_BLUE,
            BOTTOM_LEFT, GPU_BLACK,
            BOTTOM_RIGHT, GPU_BLACK,
            TexturesID::NONE),
        m_background_image(10, 10, 100, 200, TexturesID::BACKGROUND) {
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
