/* StackImpl.cpp - GBA */

#include <gba.h>
#include <Stack.h>
#include "StackImpl.h"

void StackImpl::update() {
}

void StackImpl::render() const {
    // Draw stack blocks and outline
    //#define m_pos_x 0
    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + m_stack.position().x;
    for (int i = 0; i < m_stack.height() - 2; i++) {
        // TODO grey (blink) blocks
        memcpy(
            local_screen + 32 * i,
            m_stack.field() + m_stack.width() * (i + 2),
            m_stack.width() * 2);
    }

    local_screen = (u16*) MAP_BASE_ADR(24) + m_stack.position().x;
    for (int i = 0; i < m_stack.height() - 2; i++) {
        memcpy(
            local_screen + 32 * i,
            m_stack.outline() + m_stack.width() * (i + 2),
            m_stack.width() * 2);
    }
}
