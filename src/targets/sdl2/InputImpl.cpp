/* InputImpl.cpp - SDL2 */

#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    // Joystick
    if (/* up */ false)
        input.pressed_up();
    if (/* down */ false)
        input.pressed_down();
    if (/* left */ false)
        input.pressed_left();
    if (/* right */ false)
        input.pressed_right();

    // Buttons
    if (/* a */ false)
        input.pressed_a();
    if (/* b */ false)
        input.pressed_b();
    if (/* c */ false)
        input.pressed_c();
    if (/* start */ false)
        input.pressed_start();
    if (/* settings */ false)
        input.pressed_settings();
}

