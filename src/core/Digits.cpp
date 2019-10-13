/* Digits.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Digits.h>

Digits::Digits(const Position position, const Position &parent) :
        m_value(0),
        m_position(position),
        m_parent(parent) {
    #ifdef DEBUG
    print("Digits constructor\n");
    #endif
}

void Digits::set(const uint32_t value) {
    if (value != m_value) {
        m_implementation.update_graphics(value);
    }
}

void Digits::draw() {
    m_implementation.render();
}
