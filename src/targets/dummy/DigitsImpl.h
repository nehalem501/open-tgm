/* DigitsImpl.h - Dummy */

#ifndef DIGITS_DUMMY_H
#define DIGITS_DUMMY_H

#include <TargetTypes.h>

class DigitsImpl {
    public:
        void init_graphics();
        void update_graphics(const uint32_t value);
        void render() const;
};

#endif
