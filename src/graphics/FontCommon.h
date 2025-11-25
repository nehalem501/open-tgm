/* FontCommon.h - Graphics */

#ifndef FONT_COMMON_H
#define FONT_COMMON_H

#include <iostream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H
#include "orbitron_font.h"

class FreeType {
    public:
        FreeType() : m_initialized(false) {}

        ~FreeType() {
            FT_Done_Face(m_text_face);
            FT_Done_FreeType(m_library);
        }

        void load() {
            if (m_initialized) {
                return;
            }

            FT_Error error;
            error = FT_Init_FreeType(&m_library); // TODO: check error
            if (error) {
                std::cout << "Error FT_Init_FreeType" << std::endl;
            }
            /*error = FT_Stroker_New(m_library, &m_stroker);
            if (error) {
                std::cout << "Error FT_Stroker_New" << std::endl;
            }*/
            error = FT_New_Memory_Face(m_library, orbitron_font, orbitron_font_size, 0, &m_text_face);
            /*std::string file = "Orbitron-Black.ttf";
            std::string path = "/Users/tomek/test/py/" + file;
            error = FT_New_Face(m_library, path.c_str(), 0, &m_face);*/
            if (error) {
                std::cout << "Error FT_New_Face" << std::endl;
            }
            m_initialized = true;
        }

        FT_Face text_face() { return m_text_face; }
        FT_Library library() { return m_library; }

    private:
        FT_Library m_library;
        //FT_Stroker m_stroker;
        FT_Face m_text_face;
        bool m_initialized;
};

extern FreeType freetype;

#endif // FONT_COMMON_H
