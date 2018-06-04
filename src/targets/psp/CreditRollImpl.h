/* CreditRollImpl.h - PSP */

#ifndef CREDIT_ROLL_PSP_H
#define CREDIT_ROLL_PSP_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
