/* Timer.cpp */

#include <stdint.h>
#include <Global.h>
#include <core/Timer.h>

void Core::Timer::init() {
    m_frames = 0;

    m_str[0] = 0;
    m_str[1] = 0;
    m_str[2] = 0;
    m_str[3] = 0;
    m_str[4] = 0;
    m_str[5] = 0;
}

void Core::Timer::update() {
    m_frames++;
    //m_time = 1.66666666666666666666f * m_frames;
    uint32_t m_time = (1666 * m_frames) / 1000;

    uint32_t centsec = m_time % 100;
    uint32_t sec = (m_time / 100) % 60;
    uint32_t min = (m_time / (100 * 60)) % 60;

    #ifdef DEBUG
    print("time: %02d:%02d:%02d\n", min, sec, centsec);
    #endif

    m_str[0] = min / 10;
    m_str[1] = min % 10;

    m_str[2] = sec / 10;
    m_str[3] = sec % 10;

    m_str[4] = centsec / 10;
    m_str[5] = centsec % 10;
}

void Core::Timer::start() {
    //m_time = 0.0;
    m_frames = 0;
}
