/* Timer.h */

#ifndef CORE_TIMER_H
#define CORE_TIMER_H

#include <TargetTypes.h>

namespace Core {
    class Timer {
        public:
            uint32_t m_frames;

            int m_pos_x, m_pos_y;
            uint8_t m_str[6];

            void init();
            void start();
            void update();
    };
}

#endif
