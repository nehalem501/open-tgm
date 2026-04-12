/* Orientation.h */

#ifndef ORIENTATION_H
#define ORIENTATION_H

#include <Enums.h>

class Orientation {
    public:
        inline Orientation() : m_value(0) { }

        inline void reset() { m_value = 0; }
        inline uint_fast8_t value() const { return m_value & 0b11; }

        inline void rotate(Rotation o) {
            switch (o) {
                case Rotation::Left:
                    m_value++;
                    return;
                case Rotation::Right:
                    m_value--;
                    return;
                default:
                    return;
            }
        }
    private:
        uint_fast8_t m_value;
};

#endif // ORIENTATION_H
