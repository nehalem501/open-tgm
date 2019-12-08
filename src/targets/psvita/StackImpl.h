/* StackImpl.h - PSVita */

#ifndef STACK_PSVITA_H
#define STACK_PSVITA_H

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
