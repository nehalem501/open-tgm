/* TimerImpl.h - OpenGL */

#ifndef TIMER_OPENGL_H
#define TIMER_OPENGL_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
