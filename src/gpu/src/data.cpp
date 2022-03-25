/* data.cpp - GPU */

#include <Texture.h>
#include <Glyphs.h>
#include <Debug.h>
#include "TilemapData.h"
#include "Vector.h"
#include <data.h>

#include <data/data_info.h>

struct GlyphsArray {
    Glyph glyphs[NB_GLYPHS];

    void clear() {
        Glyph empty(0, 0, 0, 0, 0);
        for (unsigned int i = 0; i < NB_GLYPHS; i++) {
            glyphs[i] = empty;
        }
    }
};

static Texture textures[TexturesID::NB_TEXTURES];

static TextureData empty_texture_data;
static TextureData frame_texture_data;

static TilemapData empty_tilemap_data;
static TilemapData blocks_tilemap_data;
static TilemapData outline_tilemap_data;

static GlyphsArray glyphs_data[Fonts::NB_FONTS];

uint32_t read_uint32(const uint8_t* data) {
    uint32_t value =
        ((uint32_t) data[3] << 0)  |
        ((uint32_t) data[2] << 8)  |
        ((uint32_t) data[1] << 16) |
        ((uint32_t) data[0] << 24);
    return value;
}

Texture& get_texture(TextureID id) {
    return textures[id];
}

const TextureData& get_texture_data(TextureID id) {
    switch (id) {
        case TexturesID::FRAME:
            return frame_texture_data;
    }

    return empty_texture_data;
}

void set_texture_data(TextureID id, const TextureData& data) {
    switch (id) {
        case TexturesID::FRAME:
            frame_texture_data = data;
            break;
    }
}

void set_tilemap_data(TextureID id, const TilemapDataEntry& entry) {
    switch (id) {
        case TexturesID::BLOCKS:
            blocks_tilemap_data.update(entry);
            break;
        case TexturesID::OUTLINE:
            outline_tilemap_data.update(entry);
            break;
    }
}

const TilemapData& get_tilemap_data(TextureID id) {
    switch (id) {
        case TexturesID::BLOCKS:
            return blocks_tilemap_data;
        case TexturesID::OUTLINE:
            return outline_tilemap_data;
    }
    return empty_tilemap_data;
}

const Glyph* get_glyph_array(Font font) {
    return glyphs_data[font].glyphs;
}

void clear_glyph_data(TextureID id) {
    switch (id) {
        case TexturesID::TEXT:
            glyphs_data[Fonts::UI_FONT].clear();
            return;
        case TexturesID::DIGITS:
            glyphs_data[Fonts::DIGITS_FONT].clear();
            return;
        case TexturesID::LABELS:
            glyphs_data[Fonts::LABEL_FONT].clear();
            return;
    }
    printd("clear_glyph_data: unknown Glyphs TextureID: " << id);
}

void set_glyph_data(TextureID id, uint8_t c, const Glyph& data) {
    switch (id) {
        case TexturesID::TEXT:
            glyphs_data[Fonts::UI_FONT].glyphs[c] = data;
            return;
        case TexturesID::DIGITS:
            glyphs_data[Fonts::DIGITS_FONT].glyphs[c] = data;
            return;
        case TexturesID::LABELS:
            glyphs_data[Fonts::LABEL_FONT].glyphs[c] = data;
            return;
    }
    printd("set_glyph_data: unknown Glyphs TextureID: " << id);
}

Vector<Reloadable*> reloadable_items;
bool loaded = false;

void register_reloadable(Reloadable* item) {
    reloadable_items.push(item);
}

void load_textures() {
    textures[0].format = TexturesFormat::RGBA8;
    textures[0].width = 8;
    textures[0].height = 8;
    uint8_t data[8 * 8 * 4];
    memset(data, 0xFFu, 8 * 8 * 4);
    load_texture(textures[0], data, 8 * 8 * 4);

    register_textures(textures_assets);
    refresh_textures(textures);

    // TODO refresh glyphs etc...
    for (size_t i = 0; i < reloadable_items.size(); i++) {
        reloadable_items[i]->refresh();
    }

    loaded = true;
}

#ifdef RESIZABLE
void reload_textures() {
    if (!loaded) {
        return;
    }

    refresh_textures(textures);

    // TODO refresh glyphs etc...
    for (size_t i = 0; i < reloadable_items.size(); i++) {
        reloadable_items[i]->refresh();
    }
}
#endif
