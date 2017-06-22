/* TimerImpl.h - Dummy */

#ifndef TIMER_DUMMY_H
#define TIMER_DUMMY_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
