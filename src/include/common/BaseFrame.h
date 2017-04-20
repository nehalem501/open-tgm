/* BaseFrame.h */

#ifndef BASE_FRAME_H
#define BASE_FRAME_H

#include <Stack.h>

class BaseFrame {
    public:
        void init(Stack *stack);

    protected:
        Stack *m_stack;
        //TODO color;
};

#endif
