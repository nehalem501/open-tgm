/* StackImpl.h - PSVita */

#ifndef STACK_PSVITA_H
#define STACK_PSVITA_H

#include <core/Stack.h>

class StackImpl : public Core::Stack {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
