/* InputImpl.h - Dummy */

#ifndef INPUT_DUMMY_H
#define INPUT_DUMMY_H

#include <common/BaseInput.h>

class InputImpl : public BaseInput {
    public:
        void init();
        void pollInputs();
};

#endif
