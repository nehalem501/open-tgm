/* Text.cpp */

#include <stddef.h>
#include <string.h>
#include <Position.h>
#include <Stack.h>
#include <Debug.h>
#include <Text.h>

Text::Text() :
        m_coordinates(0, 0),
        m_position(0, 0),
        m_layout(Layouts::NONE),
        m_font(Font::Text),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this)
{
    printd(DebugCategory::TEXT, "Text constructor: <NULL>");
}

Text::Text(
    const Position& parent,
    const Coordinates& coordinates,
    Layout layout) :
        m_coordinates(coordinates),
        m_position(coordinates.to_position() + parent),
        m_layout(layout),
        m_font(Font::Text),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    printd(DebugCategory::TEXT, "Text constructor: <NULL>");
}

Text::Text(
    const Position& parent,
    const Coordinates& coordinates,
    Layout layout,
    int color,
    const char *str) :
        m_coordinates(coordinates.x, coordinates.y),
        m_position(coordinates.to_position() + parent),
        m_layout(layout),
        m_font(Font::Text),
        m_color(color),
        m_length(strlen(str)),
        m_str(str),
        m_implementation(*this) {
    printd(DebugCategory::TEXT, "Text constructor: '", str, "'");
}

void Text::coordinates(const Coordinates& coordinates, const Position& parent) {
    Text::coordinates(coordinates, parent, m_layout);
}

void Text::coordinates(const Coordinates& coordinates, const Position& parent, Layout layout) {
    const Position position = coordinates.to_position() + parent;

    if (m_position != position ||
        m_layout != layout) {

        printd(DebugCategory::TEXT,
            "Text::coordinates: (",
            m_coordinates,
            m_position,
            ") replaced by (",
            coordinates,
            position,
            ")");

        m_coordinates = coordinates;
        m_position = position;
        m_layout = layout;
        m_implementation.update_position();
    }
}

void Text::text(const char *new_str) {
    if (m_str != new_str) {
        printd(DebugCategory::TEXT, "Text::text: ", m_str, " replaced by ", new_str);
        m_str = new_str;
        m_length = strlen(m_str);
        m_implementation.update_text();
    }
}

void Text::font(Font font) {
    if (m_font != font) {
        printd(DebugCategory::TEXT, "Text::font: ", m_font, " replaced by ", font);
        m_font = font;
        m_implementation.update_font();
    }
}

void Text::color(int color) {
    if (m_color != color) {
        printd(DebugCategory::TEXT, "Text::color: ", m_color, " replaced by ", color);
        m_color = color;
        m_implementation.update_color();
    }
}

void Text::draw() const {
    m_implementation.render();
}

#ifdef DEBUG
void printd_internal(const Font font) {
    switch (font) {
        case Font::Text:
            printd_internal("Font::Text");
            break;
        case Font::Label:
            printd_internal("Font::Label");
            break;
    }
}
#endif
