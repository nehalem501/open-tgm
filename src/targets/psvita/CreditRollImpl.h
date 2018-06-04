/* CreditRollImpl.h - PSVita */

#ifndef CREDIT_ROLL_PSVITA_H
#define CREDIT_ROLL_PSVITA_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
