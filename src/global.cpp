/* global.cpp */

#include "global.h"
#include "menu.h"
#include "stack.h"
#include "frame.h"
#include "player.h"
#include "modes.h"


void init() {
    // Init random
    initRandom();
    
    //
    input.init();
    initModes();

    frame1.init(&stack1);
    player1.init(&stack1);
    
    #warning "Global init not finished"
}

void initGraphics() {
    stack_position = Position::CENTERED,
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

    #warning "Global initGraphics not finished"
}
