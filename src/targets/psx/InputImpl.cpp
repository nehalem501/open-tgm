/* InputImpl.cpp - PSX */

#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    // Joystick
    if (/* up */ true)
        input.pressed_up();
    if (/* down */ true)
        input.pressed_down();
    if (/* left */ true)
        input.pressed_left();
    if (/* right */ true)
        input.pressed_right();

    // Buttons
    if (/* a */ true)
        input.pressed_a();
    if (/* b */ true)
        input.pressed_b();
    if (/* c */ true)
        input.pressed_c();
    if (/* start */ true)
        input.pressed_start();
    if (/* settings */ true)
        input.pressed_settings();
}
