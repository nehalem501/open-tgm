/* DigitsImpl.h - Dummy */

#ifndef DIGITS_DUMMY_H
#define DIGITS_DUMMY_H

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
};

#endif
