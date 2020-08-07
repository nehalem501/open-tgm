/* DigitsImpl.h - PSVita */

#ifndef DIGITS_PSVITA_H
#define DIGITS_PSVITA_H

#include <TargetTypes.h>

class DigitsImpl {
    public:
        void update(const uint32_t value);
        void render() const;
};

#endif
