/* TimerImpl.cpp - GPU */

#include <TargetTypes.h>
#include <Position.h>
#include <Debug.h>
#include "TimerImpl.h"

void TimerImpl::update(const uint8_t m_digits[6]) {
    printd(DebugCategory::TIMER, "Timer update");
    m_str[0] = m_digits[0] + 48;
    m_str[1] = m_digits[1] + 48;
    m_str[3] = m_digits[2] + 48;
    m_str[4] = m_digits[3] + 48;
    m_str[6] = m_digits[4] + 48;
    m_str[7] = m_digits[5] + 48;

    m_glyphs.update_text(m_str, 8);
}

void TimerImpl::layout(const Position& position) {
    printd(DebugCategory::TIMER, "Timer position:", position);
    m_glyphs.position(position);
}
