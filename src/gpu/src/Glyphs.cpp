/* Glyphs.cpp - GPU */

#include <Text.h>
#include <VertexArray.h>
#include <Glyph.h>
#include <Glyphs.h>
#include <iostream>

void init_glyphs(
    Vertex2D *vertices,
    const char *text,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    int text_color,
    float texture_width,
    float texture_height,
    int texture_tile_size,
    unsigned int length,
    size_t size) {

    ColorRGBA color = text_color_to_gpu_color(text_color);

    for (unsigned int i = 0; i < size * 4; i++) {
        vertices[i].u(0);
        vertices[i].v(0);

        vertices[i].color(color);
    }

    vertices[0].x(0);
    vertices[0].y(0);

    position_glyphs_from_string(
        vertices,
        glyphs,
        position,
        layout,
        (unsigned char*) text,
        texture_width,
        texture_height,
        texture_tile_size,
        (size_t) length,
        size);
}

void set_color(Vertex2D *vertices, const ColorRGBA& new_color, size_t size) {
    for (unsigned int i = 0; i < size * 4; i++) {
        vertices[i].color(new_color);
    }
}

void set_position(Vertex2D *vertices, const Position& position, size_t size) {
    const float x = ((float) position.x) - vertices[0].x();
    const float y = ((float) position.y) - vertices[0].y();

    for (size_t i = 0; i < size * 4; i++) {
        vertices[i].x_add(x);
        vertices[i].y_add(y);
    }
}

void position_glyphs_from_string(
    Vertex2D *vertices,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    const unsigned char* str,
    float texture_width,
    float texture_height,
    int texture_tile_size,
    size_t length,
    size_t size)
{
    float offset = 0;

    // Maybe pre-compute all texture coords like for tilemaps ?
    // TODO scaling
    float factor = 1.0f;

    #ifdef RESIZABLE
    if (texture_tile_size > 0) {
        int tts = texture_tile_size;
        int tile_size = Global::tile_size;
        while (tile_size > tts) {
            if (tile_size % tts == 0) {
                factor = tile_size / tts;
                break;
            }
            tile_size--;
        }
    }
    #else
    (void)(texture_tile_size);
    #endif

    if (str != NULL) {
        std::cout << "font: " << glyphs << ", str: " << std::string((const char*)str, length) << std::endl;
    }

    for (size_t i = 0; i < (size * 4) && i < (length * 4); i += 4) { // TODO
        const Glyph& glyph = glyphs[str[i / 4]];
        std::cout << str[i / 4] << ": x: " << glyph.x << ", y: " << glyph.y << ", w: " << glyph.width << ", h: " << glyph.height << std::endl;

        vertices[i].x(position.x + offset);
        vertices[i].y(position.y);
        vertices[i].u(glyph.x / texture_width);
        vertices[i].v(glyph.y / texture_height);

        vertices[i + 1].x(position.x + offset);
        vertices[i + 1].y(position.y + (glyph.height * factor));
        vertices[i + 1].u(glyph.x / texture_width);
        vertices[i + 1].v((glyph.y + glyph.height) / texture_height);

        vertices[i + 2].x(position.x + offset + (glyph.width * factor));
        vertices[i + 2].y(position.y + (glyph.height * factor));
        vertices[i + 2].u((glyph.x + glyph.width) / texture_width);
        vertices[i + 2].v((glyph.y + glyph.height) / texture_height);

        vertices[i + 3].x(position.x + offset + (glyph.width * factor));
        vertices[i + 3].y(position.y);
        vertices[i + 3].u((glyph.x + glyph.width) / texture_width);
        vertices[i + 3].v(glyph.y / texture_height);

        offset += glyph.offset * factor;
    }

    if (layout & Layouts::H_CENTER) {
        float x = ((int) offset) / 2;
        for (size_t i = 0; i < (size * 4) && i < (length * 4); i++) {
            vertices[i].x_add(-x);
        }
    }

    // TODO
    /*if (layout & Layouts::V_CENTER) {
        float x = ((int) offset) / 2;
        for (size_t i = 0; i < (size * 4) && i < (length * 4); i++) {
            vertices[i].x_add(-x);
        }
    }*/

    if (length < size) {
        for (size_t i = length * 4; i < size * 4; i++) {
            vertices[i].x(0);
            vertices[i].y(0);

            vertices[i].u(0);
            vertices[i].v(0);
        }
    }
}
