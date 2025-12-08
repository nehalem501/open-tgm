/* BlocksTilemap.cpp - Graphics */

#include <math.h>
#include <functional>
//#include <iostream>
#include <canvas_ity.hpp>
#include <Global.h>
#include <Utils.h>
#include "GraphicsCommon.h"
#include "Graphics.h"

Buffer draw_block_outline(uint16_t current, float size) {
    float s = ceil(size / 8.0f);
    canvas_ity::canvas context(size, size);

    context.set_color(canvas_ity::fill_style, 0, 0, 0, 0);
    context.fill_rectangle(0, 0, size, size);

    context.set_color(canvas_ity::fill_style, 1, 1, 1, 1);

    if (current & OUTLINE_LEFT) {
        context.fill_rectangle(0, 0, s, size);
    }

    if (current & OUTLINE_RIGHT) {
        context.fill_rectangle(size - s, 0, s, size);
    }

    if (current & OUTLINE_UP) {
        context.fill_rectangle(0, 0, size, s);
    }

    if (current & OUTLINE_DOWN) {
        context.fill_rectangle(0, size - s, size, s);
    }

    const size_t image_size = size * size * 4;
    uint8_t *image = new uint8_t[image_size];
    context.get_image_data(image, size, size, size * 4, 0, 0);

    return Buffer { image, image_size };
}

#include <algorithm>
#include <fstream>

void generate_outline_tilemap(float current_tile_size, std::function<void(const GeneratedTexture&)> callback) {
    int tile_size = current_tile_size;
    const int tile_nb = 16; // TODO: Use get_tile_nb

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

    canvas_ity::canvas context(texture_width, texture_height);

    for (uint16_t i = 0; i < tile_nb; i++) {
        //std::cout << "i: " << i << std::endl;
        Buffer b = draw_block_outline(i, current_tile_size);
        int x = tile_size * (i % row_size);
        int y = tile_size * (i / row_size);
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
    for (unsigned int i = 8; i < 9; i++) {
        generate_outline_tilemap(i);
    }
    return 0;
}*/
