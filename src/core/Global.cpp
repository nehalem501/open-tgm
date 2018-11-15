/* Global.cpp */

#include <MainMenu.h>
#include <Stack.h>
#include <Frame.h>
#include <Player.h>
#include <Input.h>
#include <Background.h>
#include <Game.h>
#include "../modes/modes.h"
#include <Global.h>

uint32_t rand_seed;
unsigned int stack_position;

Input input;
MainMenu menu;

void init() {
    stack_position = StackPosition::CENTERED;

    init_random();
    input.init();
    init_modes();
    init_textures();
    menu.init_graphics();
}

