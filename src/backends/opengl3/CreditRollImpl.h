/* CreditRollImpl.h - OpenGL3 */

#ifndef CREDIT_ROLL_OPENGL3_H
#define CREDIT_ROLL_OPENGL3_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
