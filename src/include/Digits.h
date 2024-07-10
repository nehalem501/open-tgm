/* Digits.h */

#ifndef DIGITS_H
#define DIGITS_H

#include <TargetTypes.h>
#include <Position.h>
#include <DigitsImpl.h>

#define MAX_DIGITS_LEN 10

class Digits {
    public:
        Digits();
        Digits(Position position);

        void layout(const Position &parent);
        void draw() const;

        #ifdef RESIZABLE
        inline void resize() { m_implementation.resize(); }
        #endif

        void set(const uint32_t value);
        inline uint32_t get() const { return m_value; }

        inline void position(Position position) { m_position = position; }; // TODO layout
        inline const Position& position() const { return m_position; }; // TODO layout

        inline const char* str() const { return m_str; }

    private:
        uint32_t m_value;
        Position m_position;
        char m_str[MAX_DIGITS_LEN];
        DigitsImpl m_implementation;
};

#endif // DIGITS_H
