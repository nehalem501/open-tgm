/* InputImpl.cpp - 3DS */

#include <3ds.h>
#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    u32 keys = hidKeysHeld();

    // Joystick
    if (keys & KEY_DUP)
        input.pressed_up();
    if (keys & KEY_DDOWN)
        input.pressed_down();
    if (keys & KEY_DLEFT)
        input.pressed_left();
    if (keys & KEY_DRIGHT)
        input.pressed_right();

    // Buttons
    if (keys & KEY_Y)
        input.pressed_a();
    if (keys & KEY_X || keys & KEY_B)
        input.pressed_b();
    if (keys & KEY_A)
        input.pressed_c();
    if (keys & KEY_START)
        input.pressed_start();
    if (keys & KEY_SELECT)
        input.pressed_settings();
}
