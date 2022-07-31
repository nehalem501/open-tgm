/* Digits.cpp */

#include <stddef.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Position.h>
#include <Debug.h>
#include <Digits.h>

Digits::Digits() :
        m_value(0),
        m_position(Position(0, 0)),
        m_str{'\0'},
        m_implementation(*this) {
    printd(DebugCategory::DIGITS, "Digits constructor");
    m_str[0] = '0';
}

Digits::Digits(Position position) :
        m_value(0),
        m_position(position),
        m_str{'\0'},
        m_implementation(*this) {
    printd(DebugCategory::DIGITS, "Digits constructor");
    m_str[0] = '0';
}

void Digits::set(const uint32_t value) {
    if (value != m_value) {
        m_str[0] = '0'; // TODO
        m_implementation.update();
    }
}

void Digits::layout(const Position &parent) {
    m_implementation.layout(
        Position(m_position.x + parent.x, m_position.y + parent.y));
}

void Digits::draw() const {
    m_implementation.render();
}
