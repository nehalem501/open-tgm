/* TextImpl.cpp - GPU */

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
    m_text.color();
}

void TextImpl::layout(const Position& /*position*/) {
    // TODO
}

void TextImpl::render() const {
    // Draw text at x, y position
}
