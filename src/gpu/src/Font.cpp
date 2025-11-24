/* Font.cpp - GPU */

#include "Font.h"

TextureID font_to_texture(FontID id) {
    switch (id) {
        case FontID::UI_FONT:
            return TextureID::TEXT;

        case FontID::LABEL_FONT:
            return TextureID::LABELS;

        case FontID::DIGITS_FONT:
            return TextureID::DIGITS;

        default:
            return TextureID::NONE;
    }
}

void Font::replace(const Glyph* new_font) {
    for (unsigned int i = 0; i < NB_GLYPHS; i++) {
        m_glyphs[i] = new_font[i];
    }
}
