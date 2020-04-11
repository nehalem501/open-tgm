/* DigitsImpl.h - GPU */

#ifndef DIGITS_GPU_H
#define DIGITS_GPU_H

#include <Position.h>
#include <TargetTypes.h>

class DigitsImpl {
    public:
        void layout(const Position &position);
        void update(const uint32_t value);
        void render() const;
};

#endif
