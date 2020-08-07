/* DigitsImpl.h - PSX */

#ifndef DIGITS_PSX_H
#define DIGITS_PSX_H

#include <TargetTypes.h>

class DigitsImpl {
    public:
        void update(const uint32_t value);
        void render() const;
};

#endif
