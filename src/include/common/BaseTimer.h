/* BaseTimer.h */

#ifndef BASE_TIMER_H
#define BASE_TIMER_H

#include <stdint.h>

class BaseTimer {
    public:
        uint32_t m_frames;
        float m_time;

        int8_t m_pos_x, m_pos_y;
        int8_t str[6];

        void init();
        void start();
        void updateTime();
};

#endif
