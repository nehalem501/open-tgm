/* TimerImpl.h - Dummy */

#ifndef TIMER_DUMMY_H
#define TIMER_DUMMY_H

#include <TargetTypes.h>
#include <Position.h>

class TimerImpl {
    public:
        void layout(const Position &position);
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
