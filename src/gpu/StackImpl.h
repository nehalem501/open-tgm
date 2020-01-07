/* StackImpl.h - GPU */

#ifndef STACK_GPU_H
#define STACK_GPU_H

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
