/* TextImpl.cpp - GBA */

#include <gba.h>
#include <Stack.h>
#include "TextImpl.h"

void TextImpl::init_graphics() {

}

void TextImpl::update_graphics() {
    if (m_has_changed) {
        m_has_changed = false;
        // Update graphics here
    }
}

void TextImpl::update_color(int8_t color) {
    if (m_color != color) {
        m_color = color;
        // Update color here
    }
}

void TextImpl::draw() const {
    // Draw text
    u16 *screen = (u16*) MAP_BASE_ADR(24);

    int x = m_pos_x;
    int y = m_pos_y;

    if (m_stack != NULL) {
        x += m_stack->m_pos_x;
        y += m_stack->m_pos_y;
    }

    if (m_color != 0) {
        for (unsigned int i = 0; i < m_length; i++) {
            if (m_str[i] == ' ') {
                screen[i + x + y * 32] = 0;
            } else {
                screen[i + x + y * 32] = m_str[i] + 44;
            }
        }
    } else {
        for (unsigned int i = 0; i < m_length; i++) {
            screen[i + x + y * 32] = m_str[i];
        }
    }
}
