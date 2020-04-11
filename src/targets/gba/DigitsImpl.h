/* DigitsImpl.h - GBA */

#ifndef DIGITS_GBA_H
#define DIGITS_GBA_H

#include <TargetTypes.h>
#include <Position.h>

class DigitsImpl {
    public:
        void layout(const Position &position);
        void update(const uint32_t value);
        void render() const;
};

#endif
