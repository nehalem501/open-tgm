/* Timer.h */

#ifndef TIMER_H
#define TIMER_H

#include <TargetTypes.h>
#include <Position.h>
#include <TimerImpl.h>

class Timer {
    public:
        Timer() { };

        void layout(const Position &position);
        void draw() const;

        #ifdef RESIZABLE
        void resize(const Position &position) {
            m_implementation.resize(position);
        }
        #endif

        void start();
        void update();

    private:
        uint32_t m_frames;
        uint8_t m_digits[6];

        TimerImpl m_implementation;
};

#endif // TIMER_H
