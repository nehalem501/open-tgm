/* TimerImpl.h - PS2 */

#ifndef TIMER_PS2_H
#define TIMER_PS2_H

#include <TargetTypes.h>

class TimerImpl {
    public:
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
