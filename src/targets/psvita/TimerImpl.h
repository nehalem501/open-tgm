/* TimerImpl.h - PSVita */

#ifndef TIMER_PSVITA_H
#define TIMER_PSVITA_H

#include <TargetTypes.h>

class TimerImpl {
    public:
        void update(const uint8_t m_digits[6]);
        void render() const;
};

#endif
