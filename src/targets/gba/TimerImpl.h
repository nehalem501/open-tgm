/* TimerImpl.h - GBA */

#ifndef TIMER_GBA_H
#define TIMER_GBA_H

#include <TargetTypes.h>
#include <Position.h>

class TimerImpl {
    public:
        void layout(const Position &position);
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
