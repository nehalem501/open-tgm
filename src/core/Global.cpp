/* Global.cpp */

#include <Menu.h>
#include <Stack.h>
#include <Frame.h>
#include <Player.h>
#include <Input.h>
#include <Background.h>
#include <Game.h>
#include "../modes/modes.h"
#include <Global.h>

void init() {
    init_random();
    input.init();
    init_modes();

    frame1.init(&stack1);
    player1.init(&stack1);

    menu.m_choose_mode.init();
}

void init_graphics() {
    stack_position = StackPosition::CENTERED,
    init_textures();

    menu.init_graphics();
    background.init_graphics();

    player1.init_graphics();
    stack1.init_graphics();
    frame1.init_graphics();
#ifdef MULTIPLAYER
    player2.init_graphics();
    stack2.init_graphics();
    frame2.init_graphics();
#endif

    game.init_graphics();
}
