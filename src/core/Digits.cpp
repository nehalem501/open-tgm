/* Digits.cpp */

#include <stddef.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Digits.h>

Digits::Digits() :
        m_value(0),
        m_position(Position(0, 0)),
        m_parent(NULL) {
    #ifdef DEBUG
    print("Digits constructor\n");
    #endif
}

Digits::Digits(Position position, Position *parent) :
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

void Digits::draw() const {
    m_implementation.render();
}
