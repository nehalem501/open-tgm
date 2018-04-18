/* TimerImpl.h - 3DS */

#ifndef TIMER_3DS_H
#define TIMER_3DS_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
