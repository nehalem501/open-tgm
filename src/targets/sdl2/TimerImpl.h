/* TimerImpl.h - SDL2 */

#ifndef TIMER_SDL2_H
#define TIMER_SDL2_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
