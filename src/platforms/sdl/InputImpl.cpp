/* InputImpl.cpp - SDL */

#include <SDL_keyboard.h>
#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    Uint8 *keys = SDL_GetKeyState(NULL);

    // Joystick
    if (keys[SDLK_w])
        input.pressed_up();
    if (keys[SDLK_s])
        input.pressed_down();
    if (keys[SDLK_a])
        input.pressed_left();
    if (keys[SDLK_d])
        input.pressed_right();

    // Buttons
    if (keys[SDLK_j])
        input.pressed_a();
    if (keys[SDLK_i])
        input.pressed_b();
    if (keys[SDLK_o])
        input.pressed_c();
    if (keys[SDLK_RETURN])
        input.pressed_start();
    if (keys[SDLK_SPACE])
        input.pressed_settings();
}
