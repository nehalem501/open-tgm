/* InputImpl.h - PSX */

#ifndef INPUT_PSX_H
#define INPUT_PSX_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
