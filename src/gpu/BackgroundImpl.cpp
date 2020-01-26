/* BackgroundImpl.cpp - GPU */

#include "Texture.h"
#include "BackgroundImpl.h"

BackgroundImpl::BackgroundImpl() :
        m_background_gradient(
            0, 0, 100, 200,
            GPU_BLUE, GPU_BLUE, GPU_BLACK, GPU_BLACK,
            NULL),
        m_background_image(0, 0, 100, 200, get_texture(TextureID::BACKGROUND)) {
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
        m_background_image.render();
    }
}
