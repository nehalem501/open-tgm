/* TimerImpl.h - PS2 */

#ifndef TIMER_PS2_H
#define TIMER_PS2_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
