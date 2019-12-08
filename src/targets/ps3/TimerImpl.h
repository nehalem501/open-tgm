/* TimerImpl.h - PS3 */

#ifndef TIMER_PS3_H
#define TIMER_PS3_H

#include <TargetTypes.h>

class TimerImpl {
    public:
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
