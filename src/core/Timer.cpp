/* Timer.cpp */

#include <cmath>
#include <stdint.h>
#include <core/Timer.h>
#include <stdio.h>
void Core::Timer::init() {
    m_frames = 0;

    str[0] = 0;
    str[1] = 0;
    str[2] = 0;
    str[3] = 0;
    str[4] = 0;
    str[5] = 0;
}

void Core::Timer::update() {
    m_frames++;
    m_time = 1.66666666666666666666f * m_frames;

    // TODO see test2.cpp

    uint32_t centsec = ((uint32_t) m_time) % 100;

    uint32_t sec = (((uint32_t) m_time) / 100);
    uint32_t min = sec / 60;
    sec = sec % 60;

    printf("%02d:%02d:%02d\n", min, sec, centsec);

    str[0] = min / 10;
    str[1] = min % 10;

    str[2] = sec / 10;
    str[3] = sec % 10;

    str[4] = centsec / 10;
    str[5] = centsec % 10;
}

void Core::Timer::start() {
    m_time = 0.0;
    m_frames = 0;
}
