/* TimerImpl.h - SDL */

#ifndef TIMER_SDL_H
#define TIMER_SDL_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
