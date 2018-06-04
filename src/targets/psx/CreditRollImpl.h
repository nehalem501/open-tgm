/* CreditRollImpl.h - PSX */

#ifndef CREDIT_ROLL_PSX_H
#define CREDIT_ROLL_PSX_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
