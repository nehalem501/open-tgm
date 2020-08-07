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

void TextImpl::layout(const Position & /*position*/) {
    // TODO
}

void TextImpl::render() const {
    // Draw text at x, y position
    u16 *screen = (u16*) MAP_BASE_ADR(24);

    int offset = 0;
    if (m_text.position().layout == Layouts::CENTERED) {
        offset = m_text.length() / 2;
    }

    const int x = m_text.position().x - offset;
    const int y = m_text.position().y;

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
