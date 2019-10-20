/* Timer.cpp */

#include <TargetTypes.h>
#include <Timer.h>

void Timer::update() {
    m_frames++;
    uint32_t m_time = (1666 * m_frames) / 1000;

    uint32_t centsec = m_time % 100;
    uint32_t sec = (m_time / 100) % 60;
    uint32_t min = (m_time / (100 * 60)) % 60;

    #ifdef DEBUG
    print("time: %02d:%02d:%02d\n", min, sec, centsec);
    #endif

    m_digits[0] = min / 10;
    m_digits[1] = min % 10;

    m_digits[2] = sec / 10;
    m_digits[3] = sec % 10;

    m_digits[4] = centsec / 10;
    m_digits[5] = centsec % 10;

    m_implementation.update(m_digits);
}

void Timer::start() {
    m_frames = 0;

    m_digits[0] = 0;
    m_digits[1] = 0;
    m_digits[2] = 0;
    m_digits[3] = 0;
    m_digits[4] = 0;
    m_digits[5] = 0;
}

void Timer::draw() const {
    m_implementation.render();
}
