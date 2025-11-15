/* BlocksTilemap.cpp - Graphics */

#include <math.h>
#include <functional>
//#include <iostream>
#include <canvas_ity.hpp>
#include <Shapes.h>
#include <Utils.h>
#include "GraphicsCommon.h"
#include "Graphics.h"

static Color* get_palette(const BlocksSwatch& swatch, size_t size) {
    canvas_ity::canvas palette(size, 1);
    palette.set_linear_gradient(canvas_ity::fill_style, 0, 0, size, 0);
    palette.add_color_stop(canvas_ity::fill_style, 0, swatch.light.r, swatch.light.g, swatch.light.b, 1);
    palette.add_color_stop(canvas_ity::fill_style, 0.5, swatch.regular.r, swatch.regular.g, swatch.regular.b, 1);
    palette.add_color_stop(canvas_ity::fill_style, 1, swatch.dark.r, swatch.dark.g, swatch.dark.b, 1);
    palette.fill_rectangle(0, 0, size, 1);

    uint8_t* palette_data = new uint8_t[size * 4];
    palette.get_image_data(palette_data, size, 1, size * 4, 0, 0);
    Color* final_palette = new Color[size];
    for (size_t i = 0; i < size; i++) {
        size_t offset = i * 4;
        final_palette[i] = Color::from_rgba8(palette_data + offset);
    }

    delete[] palette_data;

    return final_palette;
}

static Buffer draw_block(float size, const BlocksSwatch& swatch) {
    constexpr size_t palette_size = 100;
    Color* palette = get_palette(swatch, palette_size);

    // TODO: instead of HSL, generate gradient (via a small canvas) and get
    // the RGBA color in the correct position
    // improvement : use 3 colors (hightlight, main, shadow to generate the gradient)

    float s = round(size / 8.0f);
    canvas_ity::canvas context(size, size);

    context.set_linear_gradient(canvas_ity::fill_style, 0, size * 0.17, 0, size * 0.84);
    Color c = palette[35];
    context.add_color_stop(canvas_ity::fill_style, 0, c.r, c.g, c.b, 1);
    c = palette[90];
    context.add_color_stop(canvas_ity::fill_style, 1, c.r, c.g, c.b, 1);
    context.fill_rectangle(s, s, size - (s * 2), size - (s * 2));

    //context.set_linear_gradient(canvas_ity::fill_style, 3 * s, 0, size - s, 0);
    context.set_linear_gradient(canvas_ity::fill_style, 1 * s, 0, size - s, 0);
    c = palette[0];
    context.add_color_stop(canvas_ity::fill_style, 0, c.r, c.g, c.b, 1);
    c = palette[30];
    context.add_color_stop(canvas_ity::fill_style, 1, c.r, c.g, c.b, 1);
    context.fill_rectangle(0, 0, size - s, s);

    context.set_linear_gradient(canvas_ity::fill_style, 0, s * 2, 0, size - s);
    c = palette[0];
    context.add_color_stop(canvas_ity::fill_style, 0, c.r, c.g, c.b, 1);
    c = palette[80];
    context.add_color_stop(canvas_ity::fill_style, 1, c.r, c.g, c.b, 1);
    context.fill_rectangle(0, s, s, size - (s * 2));

    context.set_linear_gradient(canvas_ity::fill_style, s, 0, s * 5, 0);
    c = palette[85];
    context.add_color_stop(canvas_ity::fill_style, 0, c.r, c.g, c.b, 1);
    c = palette[99];
    context.add_color_stop(canvas_ity::fill_style, 1, c.r, c.g, c.b, 1);
    context.fill_rectangle(0, size - s, size, size);

    context.set_linear_gradient(canvas_ity::fill_style, 0, s, 0, s * 5);
    c = palette[30];
    context.add_color_stop(canvas_ity::fill_style, 0, c.r, c.g, c.b, 1);
    c = palette[99];
    context.add_color_stop(canvas_ity::fill_style, 1, c.r, c.g, c.b, 1);
    context.fill_rectangle(size - s, 0, size, size - s);

    delete[] palette;

    const size_t image_size = size * size * 4;
    uint8_t *image = new uint8_t[image_size];
    context.get_image_data(image, size, size, size * 4, 0, 0);

    return Buffer { image, image_size };
}

/*static Buffer draw_item(float size, Color c) {
    float s = round(size / 8.0f);
    canvas_ity::canvas context(size, size);

    context.set_color(canvas_ity::fill_style, 0, 0, 0, 1);
    context.fill_rectangle(s, s, size - (s * 2), size - (s * 2));

    context.set_color(canvas_ity::fill_style, c.r, c.g, c.b, c.a);
    context.fill_rectangle(0, 0, size - s, s);
    context.fill_rectangle(0, s, s, size - (s * 2));
    context.fill_rectangle(0, size - s, size - s, size);
    context.fill_rectangle(size - s, 0, size, size);

    const size_t image_size = size * size * 4;
    uint8_t *image = new uint8_t[image_size];
    context.get_image_data(image, size, size, size * 4, 0, 0);

    return Buffer { image, image_size };
}*/

static BlocksSwatch get_piece_color(tiles_t shape) {
    switch (shape) {
        case Shape::I:
            return {
                { 1, 0.52, 0.30, 1 },
                { 1, 0, 0, 1 },
                { 0.39, 0.01, 0, 1 }
            };
        case Shape::Z:
            return {
                { 0.6, 1, 0.35, 1 },
                { 0, 1, 0, 1 },
                { 0.13, 0.42, 0, 1 }
            };
        case Shape::S:
            return {
                { 0.96, 0.41, 1, 1 },
                { 1, 0, 1, 1 },
                { 0.42, 0, 0.45, 1 }
            };
        case Shape::J:
            return {
                { 0.47, 0.74, 1, 1 },
                { 0, 0, 1, 1 },
                { 0.05, 0.01, 0.46, 1 }
            };
        case Shape::L:
            return {
                { 1, 0.76, 0.43, 1 },
                { 1, 0.75, 0, 1 },
                { 0.52, 0.14, 0, 1 }
            };
        case Shape::O:
            return {
                { 1, 0.96, 0.3, 1 },
                { 1, 1, 0, 1 },
                { 0.37, 0.27, 0, 1 }
            };
        case Shape::T:
            return {
                { 0.34, 0.92, 1, 1 },
                { 0, 1, 1, 1 },
                { 0.05, 0.44, 0.72, 1 }
            };
        default:
            return {};
    }
}

/*static Color get_item_kind_color(ItemKind kind) {
    switch (kind) {
        case ItemKind::NEUTRAL:
            return { 0, 1, 0, 1 };
        case ItemKind::ATTACK:
            return { 1, 0, 0, 1 };
        case ItemKind::DEFENSE:
            return { 0, 0, 1, 1 };
        default:
            return {};
    }
}*/

#include <algorithm>
#include <fstream>

void generate_blocks_tilemap(float current_tile_size, std::function<void(const GeneratedTexture&)> callback) {
    int tile_size = current_tile_size;
    const int tile_nb = 32;

    // TODO factorize
    unsigned int tiles_pixels = tile_nb * tile_size * tile_size;
    unsigned int min_size = bit_ceil(tiles_pixels);

    unsigned int texture_width;
    unsigned int texture_height;
    unsigned int texture_pixels;
    unsigned int row_size = 0;

    do {
        row_size++;
        texture_width = bit_ceil(tile_size * row_size);
        texture_height = bit_ceil(tile_size * ((tile_nb / row_size) + ((tile_nb % row_size) % 1)));
        texture_pixels = texture_width * texture_height;
    } while (texture_pixels > min_size);

    //size_t texture_size = texture_pixels * 4;
    //uint8_t* texture_data = new uint8_t[texture_size];

    canvas_ity::canvas context(texture_width, texture_height);
    context.set_color(canvas_ity::fill_style, 0, 0, 0, 0);
    context.fill_rectangle(0, 0, tile_size, tile_size);
    context.set_color(canvas_ity::fill_style, 1, 1, 1, 1);
    context.fill_rectangle(0, tile_size, texture_width, texture_height - tile_size);

    BlocksSwatch grey = {
        { 1, 1, 1, 1 },
        { 0.76, 0.76, 0.76, 1 },
        { 0.24, 0.24, 0.24, 1 }
    };

    for (tiles_t i = 0; i <= Shape::NB_SHAPES; i++) {
        Buffer b = draw_block(
            current_tile_size,
            i == Shape::NB_SHAPES ? grey : get_piece_color(i));
        int x = tile_size * ((i + 1) % row_size);
        int y = tile_size * ((i + 1) / row_size);
        context.put_image_data(b.data, tile_size, tile_size, tile_size * 4, x, y);
        delete[] b.data;
    }

    size_t texture_size = texture_width * texture_height * 4;
    uint8_t *texture = new uint8_t[texture_size];
    context.get_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
    Buffer b = { texture, texture_size };
    GeneratedTexture t = { b, texture_width, texture_height };
    callback(t);
    /*unsigned char header[] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, (unsigned char) (texture_width & 255), (unsigned char) (texture_width >> 8), (unsigned char) (texture_height & 255), (unsigned char) (texture_height >> 8), 32, 40 };
    for (unsigned int pixel = 0; pixel < texture_height * texture_width; pixel++) {
        std::swap( texture[ pixel * 4 + 0 ], texture[ pixel * 4 + 2 ] );
    }
    std::string filename = "example" + std::to_string((int)current_tile_size) + std::string(".tga");
    std::ofstream stream( filename, std::ios::binary );
    stream.write( reinterpret_cast< char * >( header ), sizeof( header ) );
    stream.write( reinterpret_cast< char * >( texture ), texture_height * texture_width * 4 );*/
    delete[] texture;
}

/*int main() {
    for (unsigned int i = 8; i < 41; i++) {
        generate_blocks_tilemap(i);
    }
    return 0;
}*/
