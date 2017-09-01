/* HomeImpl.cpp - 3DS */

#include "HomeImpl.h"

void HomeImpl::initGraphics() {
    m_start.initGraphics();
    m_start.update_text("PRESS START");
    m_start.update_pos(17, 16);
    m_start.updateGraphics();
}

void HomeImpl::draw() const {
    if (m_start_timer > -20) {
        m_start.draw();
    }
    // Draw logo
}