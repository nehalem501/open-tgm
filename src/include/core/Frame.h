/* Frame.h */

#ifndef CORE_FRAME_H
#define CORE_FRAME_H

#include <Stack.h>

namespace Core {
    class Frame {
        public:
            void init(::Stack *stack);
            //TODO color;
        protected:
            Stack *m_stack;
    };
}

#endif
