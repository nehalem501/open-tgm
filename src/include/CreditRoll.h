/* CreditRoll.h */

#ifndef CREDIT_ROLL_H
#define CREDIT_ROLL_H

#include <CreditRollImpl.h>

/* Forward declarations to avoid dependency hell */
class Mode;

class CreditRoll {
    public:
        enum {
            None = 0,
            Playable,
            Required
        };

        CreditRoll();

        void draw() const;

        #ifdef RESIZABLE
        void resize() { m_implementation.resize(); }
        #endif

        inline void set_mode(Mode *new_mode) { m_mode = new_mode; }
        inline bool end() { return (m_counter == 0); }

    private:
        Mode *m_mode;
        unsigned int m_counter;

        CreditRollImpl m_implementation;
};

#endif // CREDIT_ROLL_H
