/* InputImpl.h - GBA */

#ifndef INPUT_GBA_H
#define INPUT_GBA_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void pollInputs();
};

#endif
