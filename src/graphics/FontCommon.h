/* FontCommon.h - Graphics */

#ifndef FONT_COMMON_H
#define FONT_COMMON_H

#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H
#include "orbitron_font.h"
#include "sadana_square_font.h"
#include "digit_font.h"

class FreeType {
    public:
        FreeType() : m_initialized(false) {}

        ~FreeType() {
            FT_Done_Face(m_text_face);
            FT_Done_Face(m_label_face);
            FT_Done_Face(m_digit_face);
            FT_Done_FreeType(m_library);
        }

        void load();

        FT_Library library() { return m_library; }

        FT_Face text_face() { return m_text_face; }
        FT_Face label_face() { return m_label_face; }
        FT_Face digit_face() { return m_digit_face; }

    private:
        FT_Library m_library;
        //FT_Stroker m_stroker;
        FT_Face m_text_face;
        FT_Face m_label_face;
        FT_Face m_digit_face;
        bool m_initialized;
};

extern FreeType freetype;

#endif // FONT_COMMON_H
