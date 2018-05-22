/* InputImpl.h - PS3 */

#ifndef INPUT_PS3_H
#define INPUT_PS3_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
