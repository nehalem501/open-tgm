/* InputImpl.cpp - SDL2 */

#include <SDL_keyboard.h>
#include <Input.h>
#include "InputImpl.h"

void get_inputs(Input& input) {
    const Uint8 *keys = SDL_GetKeyboardState(NULL);

    // Joystick
    if (keys[SDL_SCANCODE_W])
        input.pressed_up();
    if (keys[SDL_SCANCODE_S])
        input.pressed_down();
    if (keys[SDL_SCANCODE_A])
        input.pressed_left();
    if (keys[SDL_SCANCODE_D])
        input.pressed_right();

    // Buttons
    if (keys[SDL_SCANCODE_J])
        input.pressed_a();
    if (keys[SDL_SCANCODE_I])
        input.pressed_b();
    if (keys[SDL_SCANCODE_O])
        input.pressed_c();
    if (keys[SDL_SCANCODE_RETURN])
        input.pressed_start();
    if (keys[SDL_SCANCODE_SPACE])
        input.pressed_settings();
}

