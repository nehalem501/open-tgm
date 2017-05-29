/* DigitsImpl.h - Dummy */

#ifndef DIGITS_DUMMY_H
#define DIGITS_DUMMY_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <common/BaseDigits.h>

class DigitsImpl : public BaseDigits {
    public:
        void initGraphics();
        void updateGraphics(Stack *stack);
        void draw() const;
};

#endif
