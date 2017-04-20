/* StackImpl.h - Dummy */

#ifndef STACK_DUMMY_H
#define STACK_DUMMY_H

#include <common/BaseStack.h>

class StackImpl : public BaseStack {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
