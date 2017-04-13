/* BaseFrame.h */

#ifndef BASE_FRAME_H
#define BASE_FRAME_H

#include <Stack.h>

class BaseFrame {
    public:
        void init(Stack *stack);
        void initGraphics();
        void updateGraphics();
        
    private:
        Stack *m_stack;
        //TODO color;
};

#endif

