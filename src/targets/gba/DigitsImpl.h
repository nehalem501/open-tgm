/* DigitsImpl.h - GBA */

#ifndef DIGITS_GBA_H
#define DIGITS_GBA_H

#include <TargetTypes.h>

class DigitsImpl {
    public:
        void update(const uint32_t value);
        void render() const;
};

#endif
