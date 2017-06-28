/* DigitsImpl.h - GBA */

#ifndef DIGITS_GBA_H
#define DIGITS_GBA_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <core/Digits.h>

class DigitsImpl : public Core::Digits {
    public:
        void initGraphics();
        void updateGraphics(Stack *stack);
        void draw() const;
};

#endif
