/* Graphics.h - Graphics */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <functional>
#include <TargetTypes.h>
#include "../gpu/src/Glyph.h"

struct Buffer {
    uint8_t* data;
    size_t length;
};

struct GeneratedTexture {
    Buffer buffer;
    unsigned int width;
    unsigned int height;
};

void generate_blocks_tilemap(
    float current_tile_size,
    std::function<void(const GeneratedTexture&)> callback);
void generate_outline_tilemap(
    float current_tile_size,
    std::function<void(const GeneratedTexture&)> callback);
void generate_frame_texture(
    float current_tile_size,
    std::function<void(const GeneratedTexture&)> callback);
void generate_text_font(
    float current_tile_size,
    std::function<void(const GeneratedTexture&, const Glyph*)> callback);
void generate_label_font(
    float current_tile_size,
    std::function<void(const GeneratedTexture&, const Glyph*)> callback);
void generate_digit_font(
    float current_tile_size,
    std::function<void(const GeneratedTexture&, const Glyph*)> callback);

#endif // GRAPHICS_H
