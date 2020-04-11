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
    print("Text constructor\n");
    #endif
}

Text::Text(Position position) :
        m_position(position),
        m_color(0),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor\n");
    #endif
}

Text::Text(Position position, int color, const char *str) :
        m_position(position),
        m_color(color),
        m_length(0),
        m_str(NULL),
        m_implementation(*this) {
    #ifdef DEBUG
    print("Text constructor\n");
    #endif
    text(str);
}

void Text::position(const Position &position) {
    if (m_position.x != position.x || m_position.y != position.y) {
        #ifdef DEBUG
        print(
            "Text::update_position: (%d, %d) replaced by (%d, %d)\n",
            m_position.x,
            m_position.y,
            position.x,
            position.y);
        #endif
        m_position = position;
        // TODO update
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

void Text::layout(const Position &parent) {
    m_implementation.layout(parent); // TODO position
}

void Text::draw() const {
    m_implementation.render();
}
