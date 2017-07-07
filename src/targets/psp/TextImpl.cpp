/* TextImpl.cpp - PSP */

#include <Stack.h>
#include "TextImpl.h"

void TextImpl::initGraphics() {

}

void TextImpl::updateGraphics() {
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
