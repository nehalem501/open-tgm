/* BaseText.cpp */

#include <cstdlib>
#include <cstring>
#include <common/BaseText.h>

BaseText::BaseText() : m_pos_x(0), m_pos_y(0), m_has_changed(true), m_length(0),
                   m_str(NULL) {

}

BaseText::BaseText(int8_t pos_x, int8_t pos_y) : m_pos_x(pos_x), m_pos_y(pos_y),
                   m_has_changed(true), m_length(0), m_str(NULL) {

}

void BaseText::update_text(const char *new_str) {
    if (m_str != new_str) {
        m_str = new_str;
        m_length = strlen(m_str);
        m_has_changed = true;
    }
}

void BaseText::update_pos(int8_t pos_x, int8_t pos_y) {
    if (m_pos_x != pos_x || m_pos_y != pos_y) {
        m_pos_x = pos_x;
        m_pos_y = pos_y;
        m_has_changed = true;
    }
}
