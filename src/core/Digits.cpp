/* Digits.cpp */

#include <stddef.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Position.h>
#include <Digits.h>

Digits::Digits() :
        m_value(0),
        m_position(Position(0, 0)) {
    #ifdef DEBUG
    print("Digits constructor\n");
    #endif
}

Digits::Digits(Position position) :
        m_value(0),
        m_position(position) {
    #ifdef DEBUG
    print("Digits constructor\n");
    #endif
}

void Digits::set(const uint32_t value) {
    if (value != m_value) {
        m_implementation.update(value);
    }
}

void Digits::layout(const Position &parent) {
    m_implementation.layout(
        Position(m_position.x + parent.x, m_position.y + parent.y));
}

void Digits::draw() const {
    m_implementation.render();
}
