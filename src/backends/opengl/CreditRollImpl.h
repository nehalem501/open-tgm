/* CreditRollImpl.h - OpenGL */

#ifndef CREDIT_ROLL_OPENGL_H
#define CREDIT_ROLL_OPENGL_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
