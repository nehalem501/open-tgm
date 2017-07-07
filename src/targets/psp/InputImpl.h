/* InputImpl.h - PSP */

#ifndef INPUT_PSP_H
#define INPUT_PSP_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void pollInputs();
};

#endif
