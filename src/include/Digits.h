/* Digits.h */

#ifndef DIGITS_H
#define DIGITS_H

#include <TargetTypes.h>
#include <Position.h>
#include <DigitsImpl.h>

class Digits {
    public:
        Digits();
        Digits(Position position);

        void layout(const Position &parent);
        void draw() const;

        #ifdef RESIZABLE
        void resize() { m_implementation.resize(); }
        #endif

        void set(const uint32_t value);
        uint32_t get() { return m_value; }

        void position(Position position) { m_position = position; }; // TODO layout

    private:
        uint32_t m_value;
        Position m_position;
        DigitsImpl m_implementation;
};

#endif // DIGITS_H
