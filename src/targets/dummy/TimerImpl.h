/* TimerImpl.h - Dummy */

#ifndef TIMER_DUMMY_H
#define TIMER_DUMMY_H

#include <common/BaseTimer.h>

class TimerImpl : public BaseTimer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
