/* InputImpl.h - PS2 */

#ifndef INPUT_PS2_H
#define INPUT_PS2_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
