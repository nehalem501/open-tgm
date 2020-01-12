/* BackgroundImpl.cpp - GPU */

#include "Texture.h"
#include "BackgroundImpl.h"

BackgroundImpl::BackgroundImpl() :
        m_background_gradient(0, 0, 100, 200, NULL),
        m_background_image(0, 0, 100, 200, get_texture(TextureID::BACKGROUND)) {
    #ifdef DEBUG
    print("BackgroundImpl constructor\n");
    #endif

    m_background_gradient.top_left().color(0, 0, 1, 1);
    m_background_gradient.top_right().color(0, 0, 1, 1);
    m_background_gradient.bottom_left().color(0, 0, 0, 1);
    m_background_gradient.bottom_right().color(0, 0, 0, 1);
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
