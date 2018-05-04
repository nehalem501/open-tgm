/* StackImpl.cpp - GBA */

#include <gba.h>
#include "StackImpl.h"

void StackImpl::init_graphics() {
}

void StackImpl::update_graphics() {
}

void StackImpl::draw() const {
    // Draw stack blocks and outline
    //#define m_pos_x 0
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + m_pos_x;
    for (int i = 0; i < m_height - 2; i++) {
        memcpy(local_screen + 32 * i, m_field + m_width * (i + 2), m_width * 2);
    }

    local_screen = (u16*) MAP_BASE_ADR(24) + m_pos_x;
    for (int i = 0; i < m_height - 2; i++) {
        memcpy(local_screen + 32 * i, m_outline + m_width * (i + 2), m_width * 2);
    }

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        m_part[i].draw();
    }
}
