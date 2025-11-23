/* TextFont.cpp - Graphics */

#include <math.h>
#include <functional>
#include <iostream>
#include <canvas_ity.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <Global.h>
#include <Utils.h>
#include "stack_sans_font.h"
#include "GraphicsCommon.h"
#include "Graphics.h"
#include <algorithm>
#include <vector>
#include <fstream>

static const char* chars_to_render = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.,':!?";

/*static std::string format_to_string(FT_Glyph_Format format) {
    std::string s = "";
    char *a = (char *) &format;
    for (int i = 3; i >= 0; i--) {
        s = s + a[i];
    }
    return s;
}*/

class FreeType {
    public:
        FreeType() : m_initialized(false) {}

        ~FreeType() {
            FT_Done_Face(m_face);
            FT_Done_FreeType(m_library);
        }

        void load() {
            FT_Error error;
            error = FT_Init_FreeType(&m_library); // TODO: check error
            if (error) {
                std::cout << "Error FT_Init_FreeType" << std::endl;
            }
            // TODO: load from memory
            error = FT_New_Memory_Face(m_library, stack_sans_font, stack_sans_font_size, 0, &m_face); // TODO: check error
            if (error) {
                std::cout << "Error FT_New_Face" << std::endl;
            }
        }

        bool initialized() { return m_initialized; }
        FT_Face face() { return m_face; }

    private:
        FT_Library m_library;
        FT_Face m_face;
        bool m_initialized;
};

static FreeType ft;

static Buffer draw_char(FT_Face face, char c) {
    FT_Error error;
    FT_UInt glyph_index = FT_Get_Char_Index(face, c);
    error = FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER | FT_LOAD_TARGET_MONO | FT_LOAD_FORCE_AUTOHINT); // TODO: error
    if (error) {
        std::cout << "Error FT_Load_Glyph" << std::endl;
    }
    FT_GlyphSlot glyph = face->glyph;
    FT_Bitmap bitmap = glyph->bitmap;
    uint8_t* data = new uint8_t[bitmap.rows * bitmap.width];
    //std::vector<uint8_t> data;
    //std::cout << "size: " << bitmap.rows * bitmap.width << std::endl;
    //int size = 0;
    for (unsigned int y = 0; y < bitmap.rows; y++) {
        //std::cout << "y: " << y << ", pitch: " << bitmap.pitch << std::endl;
        for (unsigned int byte_index = 0; byte_index < (unsigned int) bitmap.pitch; byte_index++) {
            uint8_t byte_value = bitmap.buffer[y * bitmap.pitch + byte_index];
            //std::bitset<8> byte_value(bitmap.buffer[y * bitmap.pitch + byte_index]);
            //std::cout << "byte_index: " << byte_index << std::endl;
            //std::cout << std::bitset<8>(byte_value);
            //std::cout << "index: " << byte_index << ", width: " << bitmap.width << std::endl;
            int num_bits_done = byte_index * 8;
            unsigned int rowstart = y * bitmap.width + byte_index * 8;
            int max_index = std::min(8, (int) bitmap.width - num_bits_done);
            for (uint8_t bit_index = 0; (int) bit_index < max_index; bit_index++) {
                uint8_t bit = byte_value & (1 << (7 - bit_index));
                //std::cout << (bit ? "#" : ".");
                //size++;
                /*if (rowstart + bit_index >= bitmap.rows * bitmap.width) {
                    std::cout << "oops: rowstart: " << rowstart << ", bit_index: " << (int) bit_index << ", total: " << rowstart + bit_index << std::endl;
                    std::cout << "  bitmap.width: " << bitmap.width << ", num_bits_done: " << num_bits_done << ", max_index: " << (int) max_index << std::endl;
                }**/
                data[rowstart + bit_index] = bit ? 1 : 0;
                //data.push_back(bit ? 1 : 0);
            }
        }
        //std::cout << std::endl;
    }
    //std::cout << "size: " << size << std::endl;

    unsigned int width = bitmap.width;
    unsigned int height = bitmap.rows;

    //std::cout << "char: " << c << ", width: " << width << ", height: " << height << std::endl;

    //size = 0;
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            //size++;
            if (data[y * width + x])
                std::cout << '#';
            else
                std::cout << '.';
        }
        std::cout << std::endl;
    }
    //std::cout << "size: " << size << std::endl;
    std::cout << std::endl;
    delete[] data;

    //int size = 16;
    //canvas_ity::canvas context(size, size);

    /*context.set_color(canvas_ity::fill_style, 0, 0, 0, 0);
    context.fill_rectangle(0, 0, size, size);

    context.set_color(canvas_ity::fill_style, 1, 1, 1, 1);
    context.fill_rectangle(0, 0, s, size - s);*/

    //context.

    //const size_t image_size = size * size * 4;
    //uint8_t *image = new uint8_t[image_size];
    //context.get_image_data(image, size, size, size * 4, 0, 0);

    //return Buffer { image, image_size };
    return Buffer { NULL, 0 };
}

void generate_text_font(float current_tile_size/*, std::function<void(const GeneratedTexture&)> callback*/) {
    if (!ft.initialized()) {
        ft.load();
    }

    FT_Face face = ft.face();

    FT_UInt font_size = 24; // size 18 for 13px height, without outline
    FT_Error error = FT_Set_Pixel_Sizes(face, 0, font_size); // TODO: check error
    if (error) {
        std::cout << "Error FT_Set_Pixel_Sizes" << std::endl;
    }

    int tile_size = current_tile_size;
    const size_t glyphs_nb = 42; // TODO

    // TODO factorize
    unsigned int tiles_pixels = glyphs_nb * tile_size * tile_size;
    unsigned int min_size = bit_ceil(tiles_pixels);

    unsigned int texture_width;
    unsigned int texture_height;
    unsigned int texture_pixels;
    unsigned int row_size = 0;

    do {
        row_size++;
        texture_width = bit_ceil(tile_size * row_size);
        texture_height = bit_ceil(tile_size * ((glyphs_nb / row_size) + ((glyphs_nb % row_size) % 1)));
        texture_pixels = texture_width * texture_height;
    } while (texture_pixels > min_size);

    //canvas_ity::canvas context(texture_width, texture_height);

    //float s = round(current_tile_size / 8.0f);

    for (size_t i = 0; i < 42; i++) {
        //std::cout << "i: " << i << std::endl;
        /*Buffer b = draw_block(i, current_tile_size);
        int x = tile_size * (i % row_size);
        int y = tile_size * (i / row_size);
        context.put_image_data(b.data, tile_size, tile_size, tile_size * 4, x, y);
        delete[] b.data;*/
        draw_char(face, chars_to_render[i]);
    }

    //size_t texture_size = texture_width * texture_height * 4;
    //uint8_t *texture = new uint8_t[texture_size];
    //context.get_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
    //Buffer b = { texture, texture_size };
    //GeneratedTexture t = { b, texture_width, texture_height };
    //callback(t);
    /*unsigned char header[] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, (unsigned char) (texture_width & 255), (unsigned char) (texture_width >> 8), (unsigned char) (texture_height & 255), (unsigned char) (texture_height >> 8), 32, 40 };
    for (unsigned int pixel = 0; pixel < texture_height * texture_width; pixel++) {
        std::swap( texture[ pixel * 4 + 0 ], texture[ pixel * 4 + 2 ] );
    }
    std::string filename = "example" + std::to_string((int)current_tile_size) + std::string(".tga");
    std::ofstream stream( filename, std::ios::binary );
    stream.write( reinterpret_cast< char * >( header ), sizeof( header ) );
    stream.write( reinterpret_cast< char * >( texture ), texture_height * texture_width * 4 );*/
    //delete[] texture;
}

/*int main() {
    for (unsigned int i = 8; i < 9; i++) {
        generate_text_font(i);
    }
    return 0;
}*/
