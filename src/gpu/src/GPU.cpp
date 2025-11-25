/* GPU.cpp - GPU */

#include <string.h>
#include <Debug.h>
#include <Global.h>
#include "../graphics/Graphics.h"
#include "Texture.h"
#include "TextureDataManager.h"
#include "TilemapManager.h"
#include "FontManager.h"
#include "GPU.h"
//#include <iostream>

static GPU* current_gpu = NULL;

GPU& GPU::get_current_mut() {
    // TODO: null
    return *current_gpu;
}

void GPU::set_current(GPU* gpu) {
    current_gpu = gpu;
}

GPU::~GPU() { }

void GPU::load_textures() {
    load_empty_default_data();
    load_generated_textures();
    load_simple_textures();

    // TODO
    //textures[0] = empty_texture;

    // TODO
    //register_textures(textures_assets);
    //refresh_textures(textures);

    // TODO refresh glyphs etc...
    /*for (size_t i = 0; i < reloadable_items.size(); i++) {
        reloadable_items[i]->refresh();
    }*/

    //m_textures_loaded = true;
}

const Texture& GPU::get_texture(TextureID id) const {
    const Texture& t = m_textures[(size_t) id];
    if (t.initialized()) {
        return t;
    } else {
        return m_textures[0];
    }
}

Texture& GPU::get_texture_mut(TextureID id) {
    // TODO: what if texture doesn't exist?
    Texture& t = m_textures[(size_t) id];
    if (!t.initialized()) {
        return m_textures[0];
    } else {
        return t;
    }
}

void GPU::load_simple_textures() {
    // Load default empty texture
    Texture empty_texture(TexturesFormat::RGBA8, 8, 8, 8);
    uint8_t data[8 * 8 * 4];
    memset(data, 0xFFu, 8 * 8 * 4);
    load_texture(empty_texture, data, 8 * 8 * 4);
    m_textures[0] = empty_texture;
}

void GPU::load_generated_textures() {
    // We need current tile size
    //std::cout << "tile_size: " << Global::tile_size << std::endl;
    generate_blocks_tilemap(
        Global::tile_size,
        [&](const GeneratedTexture& texture)
    {
        load_generated_texture(
            TextureID::BLOCKS,
            TexturesFormat::RGBA8,
            Global::tile_size,
            texture.width,
            texture.height,
            texture.buffer.data,
            texture.buffer.length);

        //std::cout << "width: " << texture.width << std::endl;
        //std::cout << "height: " << texture.height << std::endl;
        //std::cout << "length: " << texture.buffer.length << std::endl;

        TilemapData& entry = TilemapManager::get_mutable().get_data_mutable(TilemapID::BLOCKS);
        entry.update(
            TilemapDataEntry(
                Global::tile_size,
                texture.width,
                texture.height,
                TilemapManager::get_tiles_nb(TilemapID::BLOCKS)));
        entry.set_initialized(true);
    });

    generate_outline_tilemap(
        Global::tile_size,
        [&](const GeneratedTexture& texture)
    {
        load_generated_texture(
            TextureID::OUTLINE,
            TexturesFormat::RGBA8,
            Global::tile_size,
            texture.width,
            texture.height,
            texture.buffer.data,
            texture.buffer.length);

        TilemapData& entry = TilemapManager::get_mutable().get_data_mutable(TilemapID::OUTLINE);
        entry.update(
            TilemapDataEntry(
                Global::tile_size,
                texture.width,
                texture.height,
                TilemapManager::get_tiles_nb(TilemapID::OUTLINE)));
        entry.set_initialized(true);
    });

    generate_frame_texture(
        Global::tile_size,
        [&](const GeneratedTexture& texture)
    {
        load_generated_texture(
            TextureID::FRAME,
            TexturesFormat::RGBA8,
            Global::tile_size,
            texture.width,
            texture.height,
            texture.buffer.data,
            texture.buffer.length);
        gpu_coord_t size = Global::tile_size;
        TextureData &entry = TextureDataManager::get_mutable().get_data_mutable(TextureDataID::FRAME);
        entry.width = texture.width;
        entry.height = texture.height;
        entry.tex_coord_top_left = TexCoord(0, 0);
        entry.tex_coord_top_right = TexCoord(size / entry.width, 0);
        entry.tex_coord_bottom_left = TexCoord(0, 1);
        entry.tex_coord_bottom_right = TexCoord(size / entry.width, 1);
    });

    generate_text_font(
        Global::tile_size,
        [&](const GeneratedTexture& texture, const Glyph* new_font)
    {
        load_generated_texture(
            TextureID::TEXT,
            TexturesFormat::RGBA8,
            Global::tile_size,
            texture.width,
            texture.height,
            texture.buffer.data,
            texture.buffer.length);

        Font& font = FontManager::get_mutable().get_font_mutable(FontID::UI_FONT);
        font.replace(new_font);
        font.set_initialized(true);
    });

    generate_label_font(
        Global::tile_size,
        [&](const GeneratedTexture& texture, const Glyph* new_font)
    {
        load_generated_texture(
            TextureID::LABELS,
            TexturesFormat::RGBA8,
            Global::tile_size,
            texture.width,
            texture.height,
            texture.buffer.data,
            texture.buffer.length);

        Font& font = FontManager::get_mutable().get_font_mutable(FontID::LABEL_FONT);
        font.replace(new_font);
        font.set_initialized(true);
    });
}

void GPU::load_generated_texture(
    const TextureID id,
    const uint8_t format,
    unsigned int texture_tile_size,
    unsigned int width,
    unsigned int height,
    const uint8_t* data,
    const size_t data_size)
{
    // TODO: generated vector textures;
    Texture texture(format, texture_tile_size, width, height);
    if (m_textures[(size_t) id].initialized()) {
        free_texture(m_textures[(size_t) id]);
    }
    load_texture(texture, data, data_size);
    m_textures[(size_t) id] = texture;
}

void GPU::load_texture(Texture& texture, const uint8_t* data, const size_t data_size) {
    alloc_texture(texture, data, data_size);
    texture.set_initialized(true);
}

void GPU::load_empty_default_data() {
    FontManager::get_mutable().load_empty(Global::tile_size);
    TilemapManager::get_mutable().load_empty(Global::tile_size);
}

#ifdef RESIZABLE
bool GPU::resize(unsigned int width, unsigned int height) {
    screen.width = width;
    screen.height = height;

    int new_tile_size = height / 27;
    /*if (height < 243 && height >= 240) {
        new_tile_size = 9; // TODO
    }*/

    if (new_tile_size == Global::tile_size) {
        return false; // TODO: bug when resizing only horizontally
    }

    Global::tile_size = new_tile_size;
    printd(DebugCategory::GPU, "width: ", screen.width, ", height: ", screen.height, ", tile: ", Global::tile_size);
    resize(width, height, new_tile_size);
    resize_textures();

    return true;
}

void GPU::resize_textures() {
    load_generated_textures();
}
#endif // RESIZABLE
