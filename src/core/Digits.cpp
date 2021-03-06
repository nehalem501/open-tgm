/* Digits.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <core/Digits.h>

Core::Digits::Digits() : m_value(0),
                   m_pos_x(0),
                   m_pos_y(0),
                   m_has_changed(false) {
    #ifdef DEBUG
    print("Digits constructor\n");
    #endif
}

void Core::Digits::init(int pos_x, int pos_y) {
    m_value = 0;

    m_pos_x = pos_x;
    m_pos_y = pos_y;
}

void Core::Digits::update(uint32_t number) {
    if (number != m_value) {
        m_value = number;
        m_has_changed = true;
    }
}
