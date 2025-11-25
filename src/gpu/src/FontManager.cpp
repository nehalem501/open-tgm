/* FontManager.cpp - GPU */

#include <Text.h>
#include "FontManager.h"

static FontManager font_manager;

const FontManager& FontManager::get() {
    return font_manager;
}

FontManager& FontManager::get_mutable() {
    return font_manager;
}

const Font& FontManager::get_font(FontID id) const {
    const Font& f = m_fonts[(size_t) id];
    if (f.initialized()) {
        return f;
    } else {
        return m_fonts[0];
    }
}

Font& FontManager::get_font_mutable(FontID id) {
    Font& f = m_fonts[(size_t) id];
    return f;
}


void FontManager::load_empty(unsigned int current_tile_size) {
    const unsigned int width = current_tile_size / 2;
    const unsigned int height = current_tile_size;
    const unsigned int offset = width + 1;

    Glyph space = Glyph(0, 0, 0, 0, offset);
    m_fonts[0].set_glyph(32, space);

    for (size_t i = 33; i < 127; i++) {
        Glyph g = Glyph(0, 0, width, height, offset);
        m_fonts[0].set_glyph(i, g);
    }

    m_fonts[0].set_initialized(true);
}

ColorRGBA text_color_to_gpu_color(int color) {
    switch (color) {
        case TextColor::RED:
            return ColorRGBA(1, 0, 0, 1);

        case TextColor::GREEN:
            return ColorRGBA(0, 1, 0, 1);

        case TextColor::BLUE:
            return ColorRGBA(0, 0, 1, 1);

        case TextColor::YELLOW:
            return ColorRGBA(1, 0.9, 0, 1);

        case TextColor::MAGENTA:
            return ColorRGBA(1, 0, 1, 1);

        case TextColor::CYAN:
            return ColorRGBA(0, 1, 1, 1);

        case TextColor::ORANGE:
            return ColorRGBA(1, 0.5, 0, 1);

        case TextColor::TRANSPARENT:
            return ColorRGBA(1, 1, 1, 0.3125);

        case TextColor::WHITE:
        default:
            return ColorRGBA(1, 1, 1, 1);
    }
}
