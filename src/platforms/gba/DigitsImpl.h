/* DigitsImpl.h - GBA */

#ifndef DIGITS_GBA_H
#define DIGITS_GBA_H

#include <TargetTypes.h>
#include <Position.h>

/* Forward declarations to avoid dependency hell */
class Digits;

class DigitsImpl {
    public:
        DigitsImpl(Digits &digits);

        void layout(const Position &position);
        void update();
        void render() const;

    private:
        Digits &m_digits;
};

#endif
