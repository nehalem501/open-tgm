/* Digits.h */

#ifndef DIGITS_H
#define DIGITS_H

#include <TargetTypes.h>
#include <Position.h>
#include <Coordinates.h>
#include <DigitsImpl.h>

#define MAX_DIGITS_LEN 10

class Digits {
    public:
        Digits();
        Digits(Position position);
        Digits(Coordinates coordinates, Position position);

        void draw() const;

        #ifdef RESIZABLE
        inline void resize(Position& parent) {
            m_position = m_coordinates.to_position() + parent;
            m_implementation.resize();
        }
        #endif

        void set(const uint32_t value);
        inline void add(const uint32_t value) { set(m_value + value ); }
        inline uint32_t get() const { return m_value; }

        void coordinates(const Coordinates& coordinates, const Position& parent);

        inline const Position& position() const { return m_position; };
        inline const Coordinates& coordinates() const { return m_coordinates; };

        inline const char* str() const { return m_str; }

    private:
        uint32_t m_value;
        Coordinates m_coordinates;
        Position m_position;
        char m_str[MAX_DIGITS_LEN];
        DigitsImpl m_implementation;
};

#endif // DIGITS_H
