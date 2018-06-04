/* CreditRollImpl.h - GBA */

#ifndef CREDIT_ROLL_GBA_H
#define CREDIT_ROLL_GBA_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
