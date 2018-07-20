/* PlayerImpl.cpp - Vulkan */

#include "PlayerImpl.h"

void PlayerImpl::init_graphics() {
}

void PlayerImpl::update_graphics() {
}

void PlayerImpl::draw() const {
    if (m_draw_ghost) {
        // Draw ghost piece
    }

    if (m_draw_piece) {
        // Draw player piece
    }

    // Draw next piece

    m_score_display.draw();
    m_level_display.draw();
    m_section_display.draw();
}
