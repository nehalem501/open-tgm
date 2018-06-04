/* CreditRollImpl.h - Dummy */

#ifndef CREDIT_ROLL_DUMMY_H
#define CREDIT_ROLL_DUMMY_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
