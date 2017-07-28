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
    initRandom();
    input.init();
    initModes();

    frame1.init(&stack1);
    player1.init(&stack1);

    menu.m_chooseMode.init();
}

void initGraphics() {
    stack_position = StackPosition::CENTERED,
    initTextures();

    menu.initGraphics();
    background.initGraphics();

    player1.initGraphics();
    stack1.initGraphics();
    frame1.initGraphics();
#ifdef MULTIPLAYER
    player2.initGraphics();
    stack2.initGraphics();
    frame2.initGraphics();
#endif

    game.initGraphics();
}
