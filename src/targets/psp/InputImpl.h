/* InputImpl.h - PSP */

#ifndef INPUT_PSP_H
#define INPUT_PSP_H

#include <pspctrl.h>
#include <core/Input.h>

class InputImpl : public Core::Input {
    public:
        void init();
        void poll_inputs();

        SceCtrlData m_pad;
};

#endif
