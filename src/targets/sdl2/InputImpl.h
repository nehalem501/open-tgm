/* InputImpl.h - SDL2 */

#ifndef INPUT_SDL2_H
#define INPUT_SDL2_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
