/* main.cpp */

#include <stdint.h>
#include <Global.h>
#include <Input.h>
#include <MainMenu.h>
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
MainMenu menu;
Background background;

int main() {
    // Init game stuff
    init();

    // Run game
    app();

    return 0;
}
