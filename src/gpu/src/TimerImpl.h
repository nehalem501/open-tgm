/* TimerImpl.h - GPU */

#ifndef TIMER_GPU_H
#define TIMER_GPU_H

#include <TargetTypes.h>
#include <Position.h>

class TimerImpl {
    public:
        void layout(const Position &position);
        void update(const uint8_t m_digits[6]);
        void render() const;

        #ifdef RESIZABLE
        void resize() { }
        #endif
};

#endif
