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
            return TextureID::TEXT;

        case Fonts::LABEL_FONT:
            return TextureID::LABELS;

        case Fonts::DIGITS_FONT:
            return TextureID::DIGITS;

        default:
            return TextureID::NONE;
    }
}

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
        int ts = tile_size;
        while (ts > tts) {
            if (ts % tts == 0) {
                factor = ts / tts;
                break;
            }
            ts--;
        }
    }
    #else
    (void)(texture_tile_size);
    #endif

    for (size_t i = 0; i < (size * 4) && i < (length * 4); i += 4) { // TODO
        const Glyph& glyph = glyphs[str[i / 4]];

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

    if (layout == Layouts::CENTERED) {
        float x = ((int) offset) / 2;
        for (size_t i = 0; i < (size * 4) && i < (length * 4); i++) {
            vertices[i].x_add(-x);
        }
    }

    if (length < size) {
        for (size_t i = length * 4; i < size * 4; i++) {
            vertices[i].x(0);
            vertices[i].y(0);

            vertices[i].u(0);
            vertices[i].v(0);
        }
    }
}
