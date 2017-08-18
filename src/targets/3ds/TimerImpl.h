/* TimerImpl.h - 3DS */

#ifndef TIMER_3DS_H
#define TIMER_3DS_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
