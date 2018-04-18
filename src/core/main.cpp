/* open-tgm.cpp */

#include <ctime>
#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <Menu.h>
#include <Game.h>
#include <Background.h>
#include <Player.h>
#include <Stack.h>
#include <Frame.h>
#include <App.h>


uint32_t rand_seed;
unsigned int stack_position;

Player player1;
Stack stack1;
Frame frame1;

#ifdef MULTIPLAYER
Player player2;
Stack stack2;
Frame frame2;
#endif

Input input;
Game game;
Menu menu;
Background background;

int main() {
    // Init game stuff
    init();

    // Init graphical assets
    init_graphics();

    // Run game
    app();

    return 0;
}
