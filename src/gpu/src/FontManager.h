/* FontManager.h - GPU */

#ifndef GPU_FONT_MANAGER_H
#define GPU_FONT_MANAGER_H

#include "Font.h"
#include "Texture.h"

ColorRGBA text_color_to_gpu_color(int color);

class FontManager {
    public:
        static const FontManager& get();
        static FontManager& get_mutable();

        const Font& get_font(FontID id) const;
        Font& get_font_mutable(FontID id);

        void load_empty(unsigned int current_tile_size);

    private:
        Font m_fonts[(size_t) FontID::NB_FONTS]; // TODO init
};

#endif // GPU_FONT_MANAGER_H
