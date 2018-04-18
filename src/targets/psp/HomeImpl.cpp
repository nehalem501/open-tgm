/* HomeImpl.cpp - PSP */

#include "HomeImpl.h"

void HomeImpl::init_graphics() {
    m_start.init_graphics();
    m_start.update_text("PRESS START");
    m_start.update_pos(20, 16);
    m_start.update_graphics();
}

void HomeImpl::draw() const {
    if (m_start_timer > -20) {
        m_start.draw();
    }
    // Draw logo
}
