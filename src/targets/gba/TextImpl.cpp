/* TextImpl.cpp - GBA */

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
}
