/* Text.cpp */

#include <stddef.h>
#include <string.h>
#include <Position.h>
#include <Stack.h>
#include <Text.h>

Text::Text() :
        m_position(0, 0),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: <NULL>\n");
    #endif
}

Text::Text(const Position& position, const Position& parent) :
        m_position(
            Position(
                position.x + parent.x,
                position.y + parent.y,
                position.layout)),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: <NULL>\n");
    #endif
}

Text::Text(
    const Position& position,
    const Position& parent,
    int color,
    const char *str) :
        m_position(
            Position(
                position.x + parent.x,
                position.y + parent.y,
                position.layout)),
        m_color(color),
        m_length(strlen(str)),
        m_str(str),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor: '%s'\n", str);
    #endif
}

void Text::position(const Position& position, const Position& parent) {
    if (m_position.x != position.x || m_position.y != position.y) {
        #ifdef DEBUG
        print(
            "Text::update_position: (%d, %d) replaced by (%d, %d)\n",
            m_position.x,
            m_position.y,
            position.x,
            position.y);
        #endif
        m_position = Position(
            position.x + parent.x,
            position.y + parent.y,
            position.layout);
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
        // TODO update
    }
}

void Text::color(int color) {
    if (m_color != color) {
        #ifdef DEBUG
        print("Text::update_color: %d replaced by %d\n", m_color, color);
        #endif
        m_color = color;
        // TODO update
    }
}

void Text::draw() const {
    m_implementation.render();
}
