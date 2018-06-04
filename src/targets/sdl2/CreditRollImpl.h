/* CreditRollImpl.h - SDL2 */

#ifndef CREDIT_ROLL_SDL2_H
#define CREDIT_ROLL_SDL2_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
