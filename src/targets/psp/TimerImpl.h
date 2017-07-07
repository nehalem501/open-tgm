/* TimerImpl.h - PSP */

#ifndef TIMER_PSP_H
#define TIMER_PSP_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
