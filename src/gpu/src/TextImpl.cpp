/* TextImpl.cpp - GPU */

#include <TargetTypes.h>
#include <Position.h>
#include <Text.h>
#include <Glyphs.h>
#include "TextImpl.h"

TextImpl::TextImpl(const Text& text) :
        m_text(text),
        m_glyphs(text, Fonts::UI_FONT) {

}

void TextImpl::update_position() {
    m_glyphs.position(m_text.position());
}

void TextImpl::update_text() {
    m_glyphs.position_glyphs(
        m_text.position(),
        m_text.layout(),
        (unsigned char*) m_text.text(),
        m_text.length());
}

void TextImpl::update_color() {
    m_glyphs.color(text_color_to_gpu_color(m_text.color()));
}

void TextImpl::render() const {
    m_glyphs.render();
}
