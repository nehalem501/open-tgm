/* timer.cpp */

#include <cmath>
#include <stdint.h>

#include "timer.h"


void Timer::init() {
    m_frames = 0;
    
    str[0] = 0;
    str[1] = 0;
    str[2] = 0;
    str[3] = 0;
    str[4] = 0;
    str[5] = 0;
}

void Timer::updateTime() {
    m_frames++;
    m_time = 1.66666666666666666666f * m_frames;
    
    // TODO see test2.cpp

    uint32_t centsec = (uint32_t) m_time;
    centsec = centsec % 100;

    uint8_t sec = floor((float) m_time / 100.0f);

    uint8_t min = floor((float) sec / 60.0f);

    sec = sec % 60;
    min = min % 60;

    //printf("%02d:%02d:%02d\n", min, sec, centsec);

    str[0] = min / 10;
    str[1] = min % 10;

    str[2] = sec / 10;
    str[3] = sec % 10;

    str[4] = centsec / 10;
    str[5] = centsec % 10;
}

void Timer::start() {
    m_time = 0.0;
    m_frames = 0;
}