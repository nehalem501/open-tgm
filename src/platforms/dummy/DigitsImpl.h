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

        void update_position();
        void update_value(size_t str_length);

        void render() const;
};

#endif
