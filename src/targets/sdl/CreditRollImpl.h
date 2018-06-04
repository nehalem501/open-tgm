/* CreditRollImpl.h - SDL */

#ifndef CREDIT_ROLL_SDL_H
#define CREDIT_ROLL_SDL_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
