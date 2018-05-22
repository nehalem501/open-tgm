/* TimerImpl.h - PS3 */

#ifndef TIMER_PS3_H
#define TIMER_PS3_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
