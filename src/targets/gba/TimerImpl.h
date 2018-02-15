/* TimerImpl.h - GBA */

#ifndef TIMER_GBA_H
#define TIMER_GBA_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
