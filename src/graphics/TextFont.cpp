/* TextFont.cpp - Graphics */

#include <math.h>
#include <functional>
#include <iostream>
#include <canvas_ity.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H
#include <Global.h>
#include <Glyph.h>
#include <Utils.h>
#include "stack_sans_font.h"
#include "GraphicsCommon.h"
#include "Graphics.h"
#include <algorithm>
#include <vector>
#include <fstream>

static const char* chars_to_render = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.,':!?";
static const size_t chars_to_render_nb = 42;

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
            /*error = FT_Stroker_New(m_library, &m_stroker);
            if (error) {
                std::cout << "Error FT_Stroker_New" << std::endl;
            }*/
            error = FT_New_Memory_Face(m_library, stack_sans_font, stack_sans_font_size, 0, &m_face); // TODO: check error
            if (error) {
                std::cout << "Error FT_New_Face" << std::endl;
            }
        }

        bool initialized() { return m_initialized; }
        FT_Face face() { return m_face; }
        FT_Library library() { return m_library; }

    private:
        FT_Library m_library;
        //FT_Stroker m_stroker;
        FT_Face m_face;
        bool m_initialized;
};

static FreeType ft;

static Image convert_bitmap(FT_Bitmap& bitmap, uint8_t value) {
    unsigned int length = bitmap.rows * bitmap.width;
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
                data[rowstart + bit_index] = bit ? value : 0;
                //data.push_back(bit ? 1 : 0);
            }
        }
        //std::cout << std::endl;
    }
    //std::cout << "size: " << size << std::endl;

    unsigned int width = bitmap.width;
    unsigned int height = bitmap.rows;

    Buffer buffer = { data, length };
    return { width, height, buffer };
}

/*static void display_image(Image& image) {
    for (unsigned int y = 0; y < image.height; y++) {
        for (unsigned int x = 0; x < image.width; x++) {
            //size++;
            switch (image.buffer.data[y * image.width + x]) {
                case 1:
                    std::cout << '#';
                    break;
                case 2:
                    std::cout << 'O';
                    break;
                default:
                    std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}*/

/*static void blit(Image& outline, Image& glyph, int shift) {
    for (unsigned int y = 0; y < glyph.height; y++) {
        for (unsigned int x = 0; x < glyph.width; x++) {
            uint8_t byte = glyph.buffer.data[y * glyph.width + x];
            if (byte) {
                outline.buffer.data[(y + shift) * outline.width + x + shift] = byte;
            }
        }
    }
}*/

static Image blit(Image& outline, Image& glyph, int outline_width) {
    size_t image_size = outline.width * outline.height * 4;
    uint8_t *image = new uint8_t[image_size];
    memset(image, 0, image_size);

    int shift_x = outline_width;
    int shift_y = outline_width;

    if ((int) outline.width - (int) glyph.width > outline_width * 2) {
        bool empty = true;
        for (unsigned int y = 0; y < outline.height; y++) {
            if (outline.buffer.data[y * outline.width]) {
                empty = false;
            }
        }
        if (empty && (glyph.width + shift_x + 1 <= outline.width)) {
            shift_x++;
        }
    }

    for (unsigned int y = 0; y < outline.height; y++) {
        for (unsigned int x = 0; x < outline.width; x++) {
            uint8_t byte = outline.buffer.data[y * outline.width + x];
            if (byte) {
                size_t p = (y * outline.width + x) * 4;
                image[p + 3] = 0xFFu;
            }
        }
    }

    for (unsigned int y = 0; y < glyph.height; y++) {
        for (unsigned int x = 0; x < glyph.width; x++) {
            uint8_t byte = glyph.buffer.data[y * glyph.width + x];
            if (byte) {
                size_t p = ((y + shift_y) * outline.width + x + shift_x) * 4;
                image[p + 0] = 0xFFu;
                image[p + 1] = 0xFFu;
                image[p + 2] = 0xFFu;
                image[p + 3] = 0xFFu;
            }
        }
    }

    Buffer b = { image, image_size };
    Image i = { outline.width, outline.height, b };

    return i;
}

static Image draw_char(FT_Face face, char c, int outline_width) {
    FT_Error error;
    error = FT_Load_Char(face, c, FT_LOAD_NO_BITMAP | FT_LOAD_TARGET_MONO /*| FT_LOAD_FORCE_AUTOHINT*/);

    FT_Stroker stroker;
    error = FT_Stroker_New(ft.library(), &stroker);
    if (error) {
        std::cout << "Error FT_Stroker_New" << std::endl;
    }

    FT_Stroker_Set(stroker, (outline_width * 64) /*- 1*/, FT_STROKER_LINECAP_BUTT, FT_STROKER_LINEJOIN_ROUND, 1);

    FT_Glyph glyph_outline;
    error = FT_Get_Glyph(face->glyph, &glyph_outline);
    if (error) {
        std::cout << "Error FT_Get_Glyph" << std::endl;
    }
    error = FT_Glyph_Stroke(&glyph_outline, stroker, 1);
    if (error) {
        std::cout << "Error FT_Glyph_Stroke: " << error << std::endl;
    }
    error = FT_Glyph_To_Bitmap(&glyph_outline, FT_RENDER_MODE_MONO, NULL, true);
    if (error) {
        std::cout << "Error FT_Glyph_To_Bitmap" << std::endl;
    }

    FT_BitmapGlyph glyph_outline_bitmap = (FT_BitmapGlyph) glyph_outline;
    Image outline_image = convert_bitmap(glyph_outline_bitmap->bitmap, 1);
    FT_Stroker_Done(stroker);
    FT_Done_Glyph(glyph_outline);

    FT_Glyph glyph;
    error = FT_Get_Glyph(face->glyph, &glyph);
    if (error) {
        std::cout << "Error FT_Get_Glyph" << std::endl;
    }
    error = FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_MONO, NULL, true);
    if (error) {
        std::cout << "Error FT_Glyph_To_Bitmap" << std::endl;
    }

    FT_BitmapGlyph glyph_bitmap = (FT_BitmapGlyph) glyph;
    Image glyph_image = convert_bitmap(glyph_bitmap->bitmap, 2);
    FT_Done_Glyph(glyph);

    //blit(outline_image, glyph_image, outline_width);

    /*if ((int) outline_image.width - (int) glyph_image.width > outline_width * 2) {
        std::cout << "o: " << outline_width << std::endl;
        std::cout << "w: " << glyph_image.width << ", h: " << glyph_image.height << std::endl;
        display_image(glyph_image);
        std::cout << "w: " << outline_image.width << ", h: " << outline_image.height << std::endl;
        display_image(outline_image);
    }*/

    //canvas_ity::canvas gradient(1, glyph_image.height);
    //canvas_ity::canvas context(outline_image.width, outline_image.height);

    Image image = blit(outline_image, glyph_image, outline_width);

    delete[] glyph_image.buffer.data;
    delete[] outline_image.buffer.data;

    return image;
}

void generate_text_font(
    float current_tile_size,
    std::function<void(const GeneratedTexture&, const Glyph*)> callback)
{
    if (!ft.initialized()) {
        ft.load();
    }

    FT_Face face = ft.face();

    /*FT_UInt font_size = 14; // size 18 for 13px height, without outline
    FT_Error error = FT_Set_Pixel_Sizes(face, 0, font_size); // TODO: check error
    if (error) {
        std::cout << "Error FT_Set_Pixel_Sizes" << std::endl;
    }*/

    int tile_size = current_tile_size;
    int text_size = round(current_tile_size * 1.2);
    int outline_width = std::max((int) floor(current_tile_size / 11.0f), 1);
    //std::cout << "outline_width: " << outline_width << std::endl;

    FT_Size_RequestRec req;
    req.type = FT_SIZE_REQUEST_TYPE_NOMINAL;
    req.width = text_size * 64;
    req.height = text_size * 64;
    req.horiResolution = 0;
    req.vertResolution = 0;

    FT_Error error = FT_Request_Size(face, &req);
    if (error) {
        std::cout << "Error FT_Set_Pixel_Sizes" << std::endl;
    }


    Glyph font[NB_GLYPHS];
    unsigned int texture_width = bit_ceil(tile_size * 2);
    unsigned int texture_height = bit_ceil(tile_size * 2);
    canvas_ity::canvas* context = new canvas_ity::canvas(texture_width, texture_height);

    int x = 0;
    int highest = 0;
    int y = 0;

    for (size_t i = 0; i < chars_to_render_nb; i++) {
        //std::cout << "i: " << i << std::endl;
        /*Buffer b = draw_block(i, current_tile_size);
        int x = tile_size * (i % row_size);
        int y = tile_size * (i / row_size);
        context.put_image_data(b.data, tile_size, tile_size, tile_size * 4, x, y);
        delete[] b.data;*/
        char c = chars_to_render[i];
        Image img = draw_char(face, c, outline_width);
        highest = std::max(highest, (int) img.height);
        if (x + img.width > texture_width) {
            if (i < chars_to_render_nb / 6) {
                unsigned int new_texture_width = 2 * texture_width;
                size_t texture_size = texture_width * texture_height * 4;
                uint8_t *texture = new uint8_t[texture_size];
                context->get_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
                delete context;
                context = new canvas_ity::canvas(new_texture_width, texture_height);
                context->put_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
                texture_width = new_texture_width;
                delete[] texture;
            } else {
                y += highest;
                x = 0;
                if (y + img.height > texture_height) {
                    unsigned int new_texture_height = 2 * texture_height;
                    size_t texture_size = texture_width * texture_height * 4;
                    uint8_t *texture = new uint8_t[texture_size];
                    context->get_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
                    delete context;
                    context = new canvas_ity::canvas(texture_width, new_texture_height);
                    context->put_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
                    texture_height = new_texture_height;
                    delete[] texture;
                }
            }
        }
        context->put_image_data(img.buffer.data, img.width, img.height, img.width * 4, x, y);
        font[(size_t) c] = Glyph(x, y, img.width, img.height, img.width - outline_width);
        x += img.width;
        //std::cout << c << ": " << "x: " << x << ", y: " << y << ", w: " << img.width << ", h: " << img.height << std::endl;
        delete[] img.buffer.data;
    }

    font[(size_t) ' '] = Glyph(0, 0, 0, 0, tile_size / 2);

    size_t texture_size = texture_width * texture_height * 4;
    uint8_t *texture = new uint8_t[texture_size];
    context->get_image_data(texture, texture_width, texture_height, texture_width * 4, 0, 0);
    delete context;
    Buffer b = { texture, texture_size };
    GeneratedTexture t = { b, texture_width, texture_height };
    callback(t, font);
    /*unsigned char header[] = { 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, (unsigned char) (texture_width & 255), (unsigned char) (texture_width >> 8), (unsigned char) (texture_height & 255), (unsigned char) (texture_height >> 8), 32, 40 };
    for (unsigned int pixel = 0; pixel < texture_height * texture_width; pixel++) {
        std::swap( texture[ pixel * 4 + 0 ], texture[ pixel * 4 + 2 ] );
    }
    std::string filename = "font" + std::to_string((int)current_tile_size) + std::string(".tga");
    std::ofstream stream( filename, std::ios::binary );
    stream.write( reinterpret_cast< char * >( header ), sizeof( header ) );
    stream.write( reinterpret_cast< char * >( texture ), texture_height * texture_width * 4 );*/
    delete[] texture;
}

/*int main() {
    for (unsigned int i = 8; i < 9; i++) {
        generate_text_font(i);
    }
    return 0;
}*/
