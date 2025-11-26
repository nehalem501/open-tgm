/* TextImpl.cpp - GPU */

#include <TargetTypes.h>
#include <Position.h>
#include <Text.h>
#include <Glyphs.h>
#include "TextImpl.h"

static GpuFontID to_gpu_font(Font font) {
    switch (font) {
        case Font::Text:
            return GpuFontID::UI_FONT;
        case Font::Label:
            return GpuFontID::LABEL_FONT;
        default:
            return GpuFontID::UI_FONT;
    }
}

TextImpl::TextImpl(const Text& text) :
        m_text(text),
        m_glyphs(
            text.text(),
            text.position(),
            text.layout(),
            text.color(),
            text.length(),
            to_gpu_font(text.font()))
{
}

void TextImpl::update_position() {
    m_glyphs.position(m_text.position());
}

void TextImpl::update_text() {
    m_glyphs.position_glyphs(
        m_text.position(),
        m_text.layout(),
        m_text.text(),
        m_text.length());
}

void TextImpl::update_color() {
    m_glyphs.color(text_color_to_gpu_color(m_text.color()));
}

void TextImpl::update_font() {
    m_glyphs.font(to_gpu_font(m_text.font()));
}

void TextImpl::render() const {
    m_glyphs.render();
}

#ifdef RESIZABLE
void TextImpl::resize() {
    // TODO
    m_glyphs.resize(m_text.position(), m_text.layout());
}
#endif
