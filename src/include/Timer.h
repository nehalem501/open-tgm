/* Timer.h */

#ifndef TIMER_H
#define TIMER_H

#include <TargetTypes.h>
#include <Position.h>
#include <TimerImpl.h>

class Timer {
    public:
        Timer() { };

        void draw() const;

        void start();
        void update();

    private:
        Position *m_parent;
        uint32_t m_frames;
        uint8_t m_digits[6];

        TimerImpl m_implementation;
};

#endif // TIMER_H
