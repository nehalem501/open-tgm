/* GpuFont.cpp - GPU */

#include "GpuFont.h"

TextureID font_to_texture(GpuFontID id) {
    switch (id) {
        case GpuFontID::UI_FONT:
            return TextureID::TEXT;

        case GpuFontID::LABEL_FONT:
            return TextureID::LABELS;

        case GpuFontID::DIGITS_FONT:
            return TextureID::DIGITS;

        default:
            return TextureID::NONE;
    }
}

void GpuFont::replace(const Glyph* new_font) {
    for (unsigned int i = 0; i < NB_GLYPHS; i++) {
        m_glyphs[i] = new_font[i];
    }
}
