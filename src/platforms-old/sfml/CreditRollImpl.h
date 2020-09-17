/* CreditRollImpl.h - SFML */

#ifndef CREDIT_ROLL_SFML_H
#define CREDIT_ROLL_SFML_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
