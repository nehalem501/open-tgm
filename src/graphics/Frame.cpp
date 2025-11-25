/* Frame.cpp - Graphics */

#include <math.h>
#include <functional>
#include <iostream>
#include <canvas_ity.hpp>
#include <Global.h>
#include <Utils.h>
#include "GraphicsCommon.h"
#include "Graphics.h"
#include <algorithm>
#include <vector>
#include <fstream>

void generate_frame_texture(
    float current_tile_size,
    std::function<void(const GeneratedTexture&)> callback)
{
    int tile_size = current_tile_size;

    unsigned int texture_width = bit_ceil(tile_size);
    unsigned int texture_height = bit_ceil(tile_size * 4);

    int s = round(current_tile_size / 8.0f);

    canvas_ity::canvas context(texture_width, texture_height);

    context.set_linear_gradient(canvas_ity::fill_style, 0, 0, 0, texture_height);
    context.add_color_stop(canvas_ity::fill_style, 0, 1, 1, 1, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.25, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.37, 0.49, 0.49, 0.49, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.43, 0.39, 0.39, 0.39, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.47, 0.35, 0.35, 0.35, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.5, 0.34, 0.34, 0.34, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.53, 0.35, 0.35, 0.35, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.57, 0.39, 0.39, 0.39, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.63, 0.49, 0.49, 0.49, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.75, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 1, 1, 1, 1, 1);
    context.fill_rectangle(s, 0, tile_size - 2 * s, texture_height);

    context.set_linear_gradient(canvas_ity::fill_style, 0, 0, 0, texture_height);
    context.add_color_stop(canvas_ity::fill_style, 0, 0.34, 0.34, 0.34, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.25, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.5, 1, 1, 1, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.75, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 1, 0.34, 0.34, 0.34, 1);
    context.fill_rectangle(0, 0, s, texture_height);

    context.set_linear_gradient(canvas_ity::fill_style, 0, 0, 0, texture_height);
    context.add_color_stop(canvas_ity::fill_style, 0, 0.34, 0.34, 0.34, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.25, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.5, 1, 1, 1, 1);
    context.add_color_stop(canvas_ity::fill_style, 0.75, 0.75, 0.75, 0.75, 1);
    context.add_color_stop(canvas_ity::fill_style, 1, 0.34, 0.34, 0.34, 1);
    context.fill_rectangle(tile_size - s, 0, s, texture_height);

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
    std::string filename = "frame" + std::to_string((int)current_tile_size) + std::string(".tga");
    std::ofstream stream( filename, std::ios::binary );
    stream.write( reinterpret_cast< char * >( header ), sizeof( header ) );
    stream.write( reinterpret_cast< char * >( texture ), texture_height * texture_width * 4 );*/
    delete[] texture;
}