/* Timer.h */

#ifndef TIMER_H
#define TIMER_H

#include <TargetTypes.h>
#include <TimerImpl.h>

class Timer {
    public:
        Timer();

        void start();
        void update();

    private:        
        uint32_t m_frames;
        uint8_t m_str[6];

        TimerImpl m_implementation;
};

#endif // TIMER_H
