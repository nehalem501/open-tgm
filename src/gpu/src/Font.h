/* Font.h - GPU */

#ifndef FONT_H
#define FONT_H

#include "Glyph.h"
#include "Texture.h"

enum struct FontID: unsigned int {
    NONE = 0,
    UI_FONT,
    LABEL_FONT,
    DIGITS_FONT,
    NB_FONTS
};

class Font {
    public:
        constexpr Font() : m_initialized(false) { }

        inline const Glyph* get_glyphs() const { return m_glyphs; }

        inline void set_glyph(size_t index, Glyph& glyph) { m_glyphs[index] = glyph; }

        bool initialized() const { return m_initialized; }
        void set_initialized(bool value) { m_initialized = value; }

        void replace(const Glyph* new_font);

    private:
        bool m_initialized;
        Glyph m_glyphs[NB_GLYPHS];
};

TextureID font_to_texture(FontID id);

#endif // FONT_H
