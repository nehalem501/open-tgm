/* InputImpl.h - SDL */

#ifndef INPUT_SDL_H
#define INPUT_SDL_H

#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();
};

#endif
