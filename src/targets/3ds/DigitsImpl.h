/* DigitsImpl.h - 3DS */

#ifndef DIGITS_3DS_H
#define DIGITS_3DS_H

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
