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
    for (int i = 0; i < m_length; i++) {
        screen[i + m_pos_x + m_pos_y * 32] = m_str[i];
    }
}
