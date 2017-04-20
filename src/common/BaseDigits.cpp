/* BaseDigits.cpp */

#include <stdint.h>
#include <common/BaseDigits.h>

BaseDigits::BaseDigits() : m_value(0),
                   m_pos_x(0),
                   m_pos_y(0),
                   m_has_changed(false) {

}

void BaseDigits::init(int8_t pos_x, int8_t pos_y) {
    m_value = 0;

    m_pos_x = pos_x;
    m_pos_y = pos_y;
}

void BaseDigits::update(uint32_t number) {
    if (number != m_value) {
        m_value = number;
        m_has_changed = true;
    }
}
