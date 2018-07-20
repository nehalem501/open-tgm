/* TimerImpl.h - Vulkan */

#ifndef TIMER_VULKAN_H
#define TIMER_VULKAN_H

#include <core/Timer.h>

class TimerImpl : public Core::Timer {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
