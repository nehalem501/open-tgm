/* Digits.cpp */

#include <stddef.h>
#include <string.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Position.h>
#include <Debug.h>
#include <Digits.h>

Digits::Digits() :
        m_value(0),
        m_coordinates(Coordinates(0, 0)),
        m_position(Position(0, 0)),
        m_str{'\0'},
        m_implementation(*this) {
    printd(DebugCategory::DIGITS, "Digits constructor");
    m_str[0] = '0';
}

Digits::Digits(Position position) :
        m_value(0),
        m_coordinates(Coordinates(0, 0)),
        m_position(position),
        m_str{'\0'},
        m_implementation(*this) {
    printd(DebugCategory::DIGITS, "Digits constructor");
    m_str[0] = '0';
}

Digits::Digits(Coordinates coordinates, Position position) :
        m_value(0),
        m_coordinates(coordinates),
        m_position(position),
        m_str{'\0'},
        m_implementation(*this) {
    printd(DebugCategory::DIGITS, "Digits constructor");
    m_str[0] = '0';
}

static size_t uint32_t_to_str(char* str, uint32_t value) {
    const char* fmt = "0123456789";
    int current = MAX_DIGITS_LEN - 1;
    uint32_t number = value;
    while (current > 0) {
        current--;
        uint32_t digit = number % 10;
        number = number / 10;
        str[current] = fmt[digit];
        if (number == 0)
            break;
    }
    if (current > 0) {
        memmove(str, str + current, MAX_DIGITS_LEN - current);
    }
    return MAX_DIGITS_LEN - current - 1;
}

void Digits::set(const uint32_t value) {
    if (value != m_value) {
        printd(DebugCategory::DIGITS, "Digits::set: (", m_value, ") replaced by (", value, ")");
        m_value = value;
        size_t length = uint32_t_to_str(m_str, m_value);
        m_implementation.update_value(length);
    }
}

void Digits::coordinates(const Coordinates& coordinates, const Position& parent) {
    const Position position = coordinates.to_position() + parent;

    if (m_position != position) {
        printd(DebugCategory::DIGITS,
            "Digits::coordinates: (",
            m_coordinates,
            m_position,
            ") replaced by (",
            coordinates,
            position,
            ")");

        m_coordinates = coordinates;
        m_position = position;
        m_implementation.update_position();
    }
};

void Digits::draw() const {
    m_implementation.render();
}
