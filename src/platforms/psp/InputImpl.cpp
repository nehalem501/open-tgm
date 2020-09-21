/* InputImpl.cpp - PSP */

#include <Input.h>
#include "InputImpl.h"
#include "pspsdk.h"

void get_inputs(Input& input) {
    SceCtrlData pad;
    sceCtrlReadBufferPositive(&pad, 1);

    // TODO Read analog stick
    // pad.Lx
    // pad.Ly

    // Joystick
    if (pad.Buttons & PSP_CTRL_UP)
        input.pressed_up();
    if (pad.Buttons & PSP_CTRL_DOWN)
        input.pressed_down();
    if (pad.Buttons & PSP_CTRL_LEFT)
        input.pressed_left();
    if (pad.Buttons & PSP_CTRL_RIGHT)
        input.pressed_right();

    // Buttons
    if ((pad.Buttons & PSP_CTRL_SQUARE) || (pad.Buttons & PSP_CTRL_LTRIGGER))
        input.pressed_a();
    if ((pad.Buttons & PSP_CTRL_TRIANGLE) || (pad.Buttons & PSP_CTRL_CROSS) || (pad.Buttons & PSP_CTRL_RTRIGGER))
        input.pressed_b();
    if (pad.Buttons & PSP_CTRL_CIRCLE)
        input.pressed_c();
    if (pad.Buttons & PSP_CTRL_START)
        input.pressed_start();
    if (pad.Buttons & PSP_CTRL_SELECT)
        input.pressed_settings();
}
