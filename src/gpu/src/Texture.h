/* Texture.h - GPU */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GPUTypes.h>
#include "Vertex.h"
#include "TextureEnums.h"

struct Texture {
    texture_t handle;
    unsigned int format, width, height;
};

struct TextureData {
    constexpr TextureData(
        gpu_float_t width,
        gpu_float_t height,
        gpu_float_t x1, gpu_float_t y1,
        gpu_float_t x2, gpu_float_t y2) :
            width(width), height(height),
            tex_coord_top_left(x1 / width, y1 / height),
            tex_coord_bottom_left(x1 / width, y2 / height),
            tex_coord_bottom_right(x2 / width, y2 / height),
            tex_coord_top_right(x2 / width, y1 / height) { };

    gpu_float_t width, height;

    TexCoord tex_coord_top_left; // 0
    TexCoord tex_coord_bottom_left; // 1
    TexCoord tex_coord_bottom_right; // 2
    TexCoord tex_coord_top_right; // 3
};

void load_textures();
void load_texture(Texture& texture, const uint8_t* img_data, const size_t img_data_size);

Texture& get_texture(TextureID id);
const TextureData& get_texture_data(TextureID id);

#ifdef RESIZABLE
void reload_textures(); // TODO
#endif

#endif // TEXTURE_H
