/* TimerImpl.h - PSX */

#ifndef TIMER_PSX_H
#define TIMER_PSX_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
