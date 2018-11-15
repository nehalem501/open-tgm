/* main.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <MainMenu.h>
#include <Game.h>
#include <Background.h>
#include <Player.h>
#include <Stack.h>
#include <Frame.h>
#include <App.h>

int main() {
    // Init game stuff
    init();

    // Run game
    app();

    return 0;
}
