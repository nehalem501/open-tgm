/* InputImpl.h - Dummy */

#ifndef INPUT_DUMMY_H
#define INPUT_DUMMY_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
