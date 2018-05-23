/* InputImpl.h - PSVita */

#ifndef INPUT_PSVITA_H
#define INPUT_PSVITA_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
