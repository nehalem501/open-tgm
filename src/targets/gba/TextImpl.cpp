/* TextImpl.cpp - GBA */

#include <gba.h>
#include <TargetTypes.h>
#include <Position.h>
#include <Text.h>
#include "TextImpl.h"

void TextImpl::update_position() {
    // Update position here
}

void TextImpl::update_text() {
    // Update text here
}

void TextImpl::update_color() {
    // Update color here
}

void TextImpl::render() const {
    // Draw text at x, y position
    u16 *screen = (u16*) MAP_BASE_ADR(24);

    const int x = m_text.position_x();
    const int y = m_text.position_y();

    if (m_text.color() != 0) {
        for (unsigned int i = 0; i < m_text.length(); i++) {
            if (m_text.text()[i] == ' ') {
                screen[i + x + y * 32] = 0;
            } else {
                screen[i + x + y * 32] = m_text.text()[i] + 44;
            }
        }
    } else {
        for (unsigned int i = 0; i < m_text.length(); i++) {
            screen[i + x + y * 32] = m_text.text()[i];
        }
    }
}
