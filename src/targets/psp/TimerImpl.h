/* TimerImpl.h - PSP */

#ifndef TIMER_PSP_H
#define TIMER_PSP_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
