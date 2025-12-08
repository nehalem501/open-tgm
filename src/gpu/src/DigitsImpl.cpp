/* DigitsImpl.cpp - GPU */

#include <Position.h>
#include <Digits.h>
#include "GpuFont.h"
#include "DigitsImpl.h"

DigitsImpl::DigitsImpl(Digits& digits) :
    m_digits(digits),
    m_glyphs(
        digits.str(),
        digits.position(),
        Layouts::NONE,
        TextColor::NONE,
        1,
        GpuFontID::DIGITS_FONT)
{ }

void DigitsImpl::update_value(size_t str_length) {
    // TODO
    m_glyphs.update_text(m_digits.str(), str_length);
}

void DigitsImpl::update_position() {
    m_glyphs.position(m_digits.position());
}

#ifdef RESIZABLE
void DigitsImpl::resize() {
    m_glyphs.resize(m_digits.position(), Layouts::NONE);
}
#endif
