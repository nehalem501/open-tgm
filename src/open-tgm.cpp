/* open-tgm.cpp */

#include <ctime>
#include <stdint.h>
#include "global.h"
#include "input.h"
#include "menu.h"
#include "background.h"
#include "player.h"
#include "stack.h"
#include "frame.h"
#include "modes.h"
#include "app.h"


uint32_t rand_seed;
uint8_t stack_position;

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
    initGraphics();
    
    // Run game    
    app();

    return 0;
}

