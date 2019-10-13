/* Digits.h */

#ifndef DIGITS_H
#define DIGITS_H

#include <TargetTypes.h>
#include <Position.h>
#include <DigitsImpl.h>

class Digits {
    public:
        Digits(const Position position, Position *parent);

        void draw();

        void set(const uint32_t value);
        uint32_t get() { return m_value; }

    private:
        uint32_t m_value;

        Position m_position;
        Position *m_parent;

        DigitsImpl m_implementation;
};

#endif // DIGITS_H
