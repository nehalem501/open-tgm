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
        const Position& position() { return m_position; }; // TODO layout

        const char* str() { return m_str; }

    private:
        uint32_t m_value;
        Position m_position;
        char m_str[MAX_DIGITS_LEN];
        DigitsImpl m_implementation;
};

#endif // DIGITS_H
