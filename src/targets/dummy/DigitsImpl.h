/* DigitsImpl.h - Dummy */

#ifndef DIGITS_DUMMY_H
#define DIGITS_DUMMY_H

#include <TargetTypes.h>
#include <Position.h>

class DigitsImpl {
    public:
        void layout(const Position &position);
        void update(const uint32_t value);
        void render() const;
};

#endif
