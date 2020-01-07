/* TimerImpl.h - GPU */

#ifndef TIMER_GPU_H
#define TIMER_GPU_H

#include <TargetTypes.h>

class TimerImpl {
    public:
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
