/* data.cpp - GPU */

#include <data/data_info.h>
#include <data.h>

#ifndef DATA_ASSET_INFO_GPU_H
extern AssetData asset_data(NULL);
#endif

const TextureData& get_texture_data(TextureID id) {
    return asset_data.get_texture_data(id);
}

const Glyph* get_glyph_array(Font font) {
    return asset_data.get_glyphs_data(font);
}

const Glyph* AssetData::get_glyphs_data(Font font) const {
    TextureID id = TexturesID::NONE;

    switch (font) {
        case Fonts::UI_FONT:
            id = TexturesID::TEXT;
            break;

        //case Fonts::LABEL_FONT:
        //    break; // TODO

        case Fonts::DIGITS_FONT:
            id = TexturesID::DIGITS;
            break;
    }

    return m_entries[id].get_item().get_glyphs();
}

const TextureData& AssetData::get_texture_data(const TextureID texture) const {
    return m_entries[texture].get_item().get_texture();
}

/*const TilemapData& AssetData::get_tilemap_data(const TextureID texture) const {
    return NULL;
}*/