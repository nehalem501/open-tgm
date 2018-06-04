/* CreditRollImpl.h - PS2 */

#ifndef CREDIT_ROLL_PS2_H
#define CREDIT_ROLL_PS2_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
