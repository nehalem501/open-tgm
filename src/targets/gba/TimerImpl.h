/* TimerImpl.h - GBA */

#ifndef TIMER_GBA_H
#define TIMER_GBA_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
