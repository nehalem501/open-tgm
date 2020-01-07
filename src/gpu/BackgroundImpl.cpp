/* BackgroundImpl.cpp - GPU */

#include "BackgroundImpl.h"

void BackgroundImpl::render(const bool options) const {
    if (options) {
        // Draw settings background
    } else {
        // Draw game background
        m_image.render();
    }
}
