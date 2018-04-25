/* Text.cpp */

#include <string.h>
#include <Stack.h>
#include <core/Text.h>

Core::Text::Text() :
        m_pos_x(0),
        m_pos_y(0),
        m_color(0),
        m_has_changed(true),
        m_length(0),
        m_str(NULL),
        m_stack(NULL) {

}

Core::Text::Text(int pos_x, int pos_y) :
        m_pos_x(pos_x),
        m_pos_y(pos_y),
        m_color(0),
        m_has_changed(true),
        m_length(0),
        m_str(NULL),
        m_stack(NULL) {

}

Core::Text::Text(int pos_x, int pos_y, int color, const char *str) :
        m_pos_x(pos_x),
        m_pos_y(pos_y),
        m_color(color),
        m_has_changed(true),
        m_length(0),
        m_str(NULL),
        m_stack(NULL) {
    update_text(str);
}

Core::Text::Text(Stack *stack, int pos_x, int pos_y) :
        m_pos_x(pos_x),
        m_pos_y(pos_y),
        m_color(0),
        m_has_changed(true),
        m_length(0),
        m_str(NULL),
        m_stack(stack) {

}

Core::Text::Text(Stack *stack, int pos_x, int pos_y,
                 int color, const char *str) : m_pos_x(pos_x),
                                               m_pos_y(pos_y),
                                               m_color(color),
                                               m_has_changed(true),
                                               m_length(0),
                                               m_str(NULL),
                                               m_stack(stack) {
    update_text(str);
}

void Core::Text::update_text(const char *new_str) {
    if (m_str != new_str) {
        m_str = new_str;
        m_length = strlen(m_str);
        m_has_changed = true;
    }
}

void Core::Text::update_pos(int pos_x, int pos_y) {
    if (m_pos_x != pos_x || m_pos_y != pos_y) {
        m_pos_x = pos_x;
        m_pos_y = pos_y;
        m_has_changed = true;
    }
}

void Core::Text::update_stack(Stack *new_stack) {
    if (m_stack != new_stack) {
        m_stack = new_stack;
        m_has_changed = true;
    }
}
