/* Glyphs.cpp - GPU */

#include <Text.h>
#include <VertexArray.h>
#include <Glyph.h>
#include <Glyphs.h>

ColorRGBA text_color_to_gpu_color(int color) {
    switch (color) {
        case TextColor::RED:
            return ColorRGBA(1, 0, 0, 1);

        case TextColor::GREEN:
            return ColorRGBA(0, 1, 0, 1);

        case TextColor::BLUE:
            return ColorRGBA(0, 0, 1, 1);

        case TextColor::YELLOW:
            return ColorRGBA(1, 1, 0, 1);

        case TextColor::MAGENTA:
            return ColorRGBA(1, 0, 1, 1);

        case TextColor::CYAN:
            return ColorRGBA(0, 1, 1, 1);

        case TextColor::ORANGE:
            return ColorRGBA(1, 0.5, 0, 1);

        case TextColor::TRANSPARENT:
            return ColorRGBA(1, 1, 1, 0.3125);

        case TextColor::WHITE:
        default:
            return ColorRGBA(1, 1, 1, 1);
    }
}

TextureID font_to_texture(Font font) {
    switch (font) {
        case Fonts::UI_FONT:
            return TexturesID::TEXT;

        case Fonts::LABEL_FONT:
            return TexturesID::LABELS;

        case Fonts::DIGITS_FONT:
            return TexturesID::DIGITS;

        default:
            return TexturesID::NONE;
    }
}

void init_glyphs_text(
    Vertex2D *vertices,
    const Text& text,
    const Glyph *glyphs,
    size_t size)
{
    init_glyphs(vertices, text.text(), glyphs, text.position(), text.layout(), text.color(), text.length(), size);
}

void init_glyphs(
    Vertex2D *vertices,
    const char *text,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    int text_color,
    unsigned int length,
    size_t size) {

    ColorRGBA color = text_color_to_gpu_color(text_color);

    for (unsigned int i = 0; i < size * 4; i++) {
        vertices[i].u = 0;
        vertices[i].v = 0;

        vertices[i].r = color.r;
        vertices[i].g = color.b;
        vertices[i].b = color.g;
        vertices[i].a = color.a;
    }

    vertices[0].x = 0;
    vertices[0].y = 0;

    position_glyphs_from_string(
        vertices,
        glyphs,
        position,
        layout,
        (unsigned char*) text,
        (size_t) length,
        size);
}

void set_color(Vertex2D *vertices, const ColorRGBA& new_color, size_t size) {
    for (unsigned int i = 0; i < size * 4; i++) {
        vertices[i].color(new_color);
    }
}

void set_position(Vertex2D *vertices, const Position& position, size_t size) {
    gpu_float_t x = ((gpu_float_t) position.x) - vertices[0].x;
    gpu_float_t y = ((gpu_float_t) position.y) - vertices[0].y;

    for (size_t i = 0; i < size * 4; i++) {
        vertices[i].x += x;
        vertices[i].y += y;
    }
}

void position_glyphs_from_string(
    Vertex2D *vertices,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    const unsigned char* str,
    size_t length,
    size_t size) {

    gpu_float_t offset = 0;
    gpu_float_t texture_width = 64.0f;
    gpu_float_t texture_height = 64.0f;

    //print("%s x: %d, y: %d, layout: %d\n", str, position.x, position.y, (int)layout);

    for (size_t i = 0; i < (size * 4) && i < (length * 4); i += 4) { // TODO
        const Glyph& glyph = glyphs[str[i / 4]];

        //Glyph glyph = { 0, 0, (gpu_float_t) tile_size, (gpu_float_t) tile_size, (gpu_float_t) tile_size + 1};
        //Glyph glyph(0, 0, tile_size, tile_size, tile_size + 1);

        vertices[i].x = position.x + offset;
        vertices[i].y = position.y;
        vertices[i].u = glyph.x / texture_width;
        vertices[i].v = glyph.y / texture_height;

        vertices[i + 1].x = position.x + offset;
        vertices[i + 1].y = position.y + glyph.height;
        vertices[i + 1].u = glyph.x / texture_width;
        vertices[i + 1].v = (glyph.y + glyph.height) / texture_height;

        vertices[i + 2].x = position.x + offset + glyph.width;
        vertices[i + 2].y = position.y + glyph.height;
        vertices[i + 2].u = (glyph.x + glyph.width) / texture_width;
        vertices[i + 2].v = (glyph.y + glyph.height) / texture_height;

        vertices[i + 3].x = position.x + offset + glyph.width;
        vertices[i + 3].y = position.y;
        vertices[i + 3].u = (glyph.x + glyph.width) / texture_width;
        vertices[i + 3].v = glyph.y / texture_height;

        offset += glyph.offset;
    }

    if (layout == Layouts::CENTERED) {
        gpu_float_t x = ((int) offset) / 2;
        for (size_t i = 0; i < (size * 4) && i < (length * 4); i++) {
            vertices[i].x -= x;
        }
    }

    if (length < size) {
        for (unsigned int i = length * 4; i < size * 4; i++) {
            vertices[i].x = 0;
            vertices[i].y = 0;

            vertices[i].u = 0;
            vertices[i].v = 0;
        }
    }
}
