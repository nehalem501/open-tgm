/* CreditRollImpl.h - 3DS */

#ifndef CREDIT_ROLL_3DS_H
#define CREDIT_ROLL_3DS_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
