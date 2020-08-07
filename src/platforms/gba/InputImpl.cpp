/* InputImpl.cpp - GBA */

#include <gba.h>
#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    // Joystick
    if (~(REG_KEYINPUT) & KEY_UP)
        input.pressed_up();
    if (~(REG_KEYINPUT) & KEY_DOWN)
        input.pressed_down();
    if (~(REG_KEYINPUT) & KEY_LEFT)
        input.pressed_left();
    if (~(REG_KEYINPUT) & KEY_RIGHT)
        input.pressed_right();

    // Buttons
    if (~(REG_KEYINPUT) & KEY_B)
        input.pressed_a();
    if (~(REG_KEYINPUT) & KEY_A)
        input.pressed_b();
    if (~(REG_KEYINPUT) & KEY_R)
        input.pressed_c();
    if (~(REG_KEYINPUT) & KEY_START)
        input.pressed_start();
    if (~(REG_KEYINPUT) & KEY_SELECT)
        input.pressed_settings();
}