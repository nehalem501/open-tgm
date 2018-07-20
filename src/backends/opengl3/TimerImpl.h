/* TimerImpl.h - OpenGL3 */

#ifndef TIMER_OPENGL3_H
#define TIMER_OPENGL3_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
