/* InputImpl.h - 3DS */

#ifndef INPUT_3DS_H
#define INPUT_3DS_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void pollInputs();
};

#endif
