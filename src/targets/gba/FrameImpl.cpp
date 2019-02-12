/* FrameImpl.cpp - GBA */

#include <gba.h>
#include "FrameImpl.h"

void FrameImpl::init_graphics() {
}

void FrameImpl::update_graphics() {
}

void Frame::draw() const {
    // Left part of frame
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + m_stack->m_pos_x - 1;
    for (int i = 0; i < 12; i++) {
        local_screen[32 * i] = 128 + i;
    }
    for (int i = 0; i < 8; i++) {
        local_screen[32 * (i + 12)] = (139 - i) | 0x0800u;
    }

    // Right part of frame
    local_screen = (u16*) MAP_BASE_ADR(16) + m_stack->m_pos_x + 10;
    for (int i = 0; i < 8; i++) {
        local_screen[32 * i] = 132 + i;
    }
    for (int i = 0; i < 12; i++) {
        local_screen[32 * (i + 8)] = (139 - i) | 0x0800u;
    }
}
