/* FontCommon.cpp - Graphics */

#include "FontCommon.h"

FreeType freetype;

void FreeType::load() {
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
    /*std::string file = "Orbitron-Black.ttf";
    std::string path = "/Users/tomek/test/py/" + file;
    error = FT_New_Face(m_library, path.c_str(), 0, &m_face);*/
    error = FT_New_Memory_Face(m_library, orbitron_font, orbitron_font_size, 0, &m_text_face);
    if (error) {
        std::cout << "Error text FT_New_Face" << std::endl;
    }
    error = FT_New_Memory_Face(m_library, sadana_square_font, sadana_square_font_size, 0, &m_label_face);
    if (error) {
        std::cout << "Error label FT_New_Face" << std::endl;
    }
    m_initialized = true;
}
