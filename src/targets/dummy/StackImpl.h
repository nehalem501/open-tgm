/* StackImpl.h - Dummy */

#ifndef STACK_DUMMY_H
#define STACK_DUMMY_H

/* Forward declarations to avoid dependency hell */
class Stack;

class StackImpl {
    public:
        void update(const Stack& stack);
        void render() const;
};

#endif
