/* CreditRoll.h */

#ifndef CORE_CREDIT_ROLL_H
#define CORE_CREDIT_ROLL_H

#include <TargetTypes.h>

/* Forward declarations to avoid dependency hell */
class Mode;

namespace Core {
    class CreditRoll {
        private:
            ::Mode *m_mode;
            unsigned int m_counter;

        public:
            CreditRoll();
            inline void set_mode(::Mode *new_mode) { m_mode = new_mode; }
            inline bool end() { return (m_counter == 0); }

        enum {
            None = 0,
            Playable,
            Required
        };
    };
}

#endif
