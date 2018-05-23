/* TimerImpl.h - PSVita */

#ifndef TIMER_PSVITA_H
#define TIMER_PSVITA_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
