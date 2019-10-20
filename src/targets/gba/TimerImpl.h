/* TimerImpl.h - GBA */

#ifndef TIMER_GBA_H
#define TIMER_GBA_H

#include <TargetTypes.h>

class TimerImpl {
    public:
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
