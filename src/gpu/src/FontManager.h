/* FontManager.h - GPU */

#ifndef GPU_FONT_MANAGER_H
#define GPU_FONT_MANAGER_H

#include "GpuFont.h"
#include "Texture.h"

ColorRGBA text_color_to_gpu_color(int color);

class FontManager {
    public:
        static const FontManager& get();
        static FontManager& get_mutable();

        const GpuFont& get_font(GpuFontID id) const;
        GpuFont& get_font_mutable(GpuFontID id);

        void load_empty(unsigned int current_tile_size);

    private:
        GpuFont m_fonts[(size_t) GpuFontID::NB_FONTS]; // TODO init
};

#endif // GPU_FONT_MANAGER_H
