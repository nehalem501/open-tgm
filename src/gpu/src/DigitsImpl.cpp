/* DigitsImpl.cpp - GPU */

#include <Position.h>
#include <Digits.h>
#include "DigitsImpl.h"

DigitsImpl::DigitsImpl(Digits& digits) :
    m_digits(digits),
    m_glyphs(
        digits.str(),
        digits.position(),
        Layouts::NONE,
        TextColor::NONE,
        1,
        Fonts::DIGITS_FONT)
{ }

void DigitsImpl::update() {
    // TODO
    m_digits.str();
}

void DigitsImpl::layout(const Position &position) {
    // TODO
    m_glyphs.position(position);
}

void DigitsImpl::render() const {
    //m_glyphs.render();
}
