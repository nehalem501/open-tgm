/* Text.cpp */

#include <stddef.h>
#include <string.h>
#include <Position.h>
#include <Stack.h>
#include <Text.h>

Text::Text() :
        m_coordinates(0, 0),
        m_position(0, 0),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: <NULL>\n");
    #endif
}

Text::Text(const Coordinates& coordinates, const Position& parent) :
        m_coordinates(coordinates),
        m_position(coordinates.to_position() + parent),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: <NULL>\n");
    #endif
}

Text::Text(
    const Position& parent,
    const Coordinates& coordinates,
    int color,
    const char *str) :
        m_coordinates(coordinates.x, coordinates.y),
        m_position(coordinates.to_position() + parent),
        m_color(color),
        m_length(strlen(str)),
        m_str(str),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: '%s'\n", str);
    #endif
}

void Text::position(const Coordinates& coordinates, const Position& parent) {
    const Position position = coordinates.to_position() + parent;

    if (m_position.x != position.x ||
        m_position.y != position.y ||
        m_coordinates.x != coordinates.x ||
        m_coordinates.y != coordinates.y) {

        #ifdef DEBUG
        print(
            "Text::update_position: (%d, %d) replaced by (%d, %d)\n",
            m_position.x,
            m_position.y,
            position.x,
            position.y);
        #endif

        m_coordinates = coordinates;
        m_position = position;
        m_implementation.update_position();
    }
}

void Text::text(const char *new_str) {
    if (m_str != new_str) {
        #ifdef DEBUG
        print("Text::update_text: %s replaced by %s\n", m_str, new_str);
        #endif
        m_str = new_str;
        m_length = strlen(m_str);
        m_implementation.update_text();
    }
}

void Text::color(int color) {
    if (m_color != color) {
        #ifdef DEBUG
        print("Text::update_color: %d replaced by %d\n", m_color, color);
        #endif
        m_color = color;
        m_implementation.update_color();
    }
}

void Text::draw() const {
    m_implementation.render();
}
