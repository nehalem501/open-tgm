/* StackImpl.h - GBA */

#ifndef STACK_GBA_H
#define STACK_GBA_H

/* Forward declarations to avoid dependency hell */
class Stack;

class StackImpl {
    public:
        StackImpl(Stack& stack) : m_stack(stack) { };
        void update();
        void render() const;

    private:
        Stack& m_stack;
};

#endif
