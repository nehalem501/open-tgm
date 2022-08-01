/* Texture.h - GPU */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GPUTypes.h>
#include <data.h>
#include "Vertex.h"
#include "TextureEnums.h"

class Texture {
    public:
        constexpr Texture() :
            m_handle(),
            m_format(0),
            m_initialized(false),
            m_tile_size(0),
            m_width(0),
            m_height(0) { }

        Texture(
            //texture_t handle,
            uint8_t format,
            unsigned int texture_tile_size,
            unsigned int width,
            unsigned int height) :
                //m_handle(handle),
                m_format(format),
                m_initialized(false),
                m_tile_size(texture_tile_size),
                m_width(width),
                m_height(height) { }

        const texture_t& handle() const { return m_handle; }
        uint8_t format() const { return m_format; }
        bool initialized() const { return m_initialized; }
        unsigned int texture_tile_size() const { return m_tile_size; }
        unsigned int width() const { return m_width; }
        unsigned int height() const { return m_height; }

        void set_initialized(bool value) { m_initialized = value; }
        texture_t* handle_ptr() { return &m_handle; }

    private:
        texture_t m_handle;
        uint8_t m_format;
        bool m_initialized;
        unsigned int m_tile_size;
        unsigned int m_width, m_height;
};

struct TextureData {
    constexpr TextureData() :
        width(0), height(0),
            tex_coord_top_left(0, 0),
            tex_coord_bottom_left(0, 0),
            tex_coord_bottom_right(0, 0),
            tex_coord_top_right(0, 0) { };

    constexpr TextureData(
        gpu_texcoord_t width,
        gpu_texcoord_t height,
        gpu_texcoord_t x1, gpu_texcoord_t y1,
        gpu_texcoord_t x2, gpu_texcoord_t y2) :
            width(width), height(height),
            tex_coord_top_left(x1 / width, y1 / height),
            tex_coord_bottom_left(x1 / width, y2 / height),
            tex_coord_bottom_right(x2 / width, y2 / height),
            tex_coord_top_right(x2 / width, y1 / height) { };

    gpu_texcoord_t width, height;

    TexCoord tex_coord_top_left; // 0
    TexCoord tex_coord_bottom_left; // 1
    TexCoord tex_coord_bottom_right; // 2
    TexCoord tex_coord_top_right; // 3
};

void load_textures();

void load_texture(Texture& texture, const uint8_t* img_data, const size_t img_data_size);
void free_texture(Texture& texture);

void register_textures(const Assets& assets);
void refresh_textures(Texture* textures);

//void read_texture(Texture* textures, const uint8_t* data, const size_t size);
//void read_texture_data(const TextureFileHeaderData& header, Texture* textures, const uint8_t* data, const size_t size);
//void read_texture_header(TextureFileHeaderData& header, const uint8_t* data, const size_t size);

Texture& get_texture(TextureID id);
const TextureData& get_texture_data(TextureID id);
void set_texture_data(TextureID id, const TextureData& data);

void refresh_texture_data();

#ifdef RESIZABLE
void reload_textures(); // TODO
#endif

#endif // TEXTURE_H
