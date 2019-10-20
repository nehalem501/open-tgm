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

#ifdef TARGET_SDL
#include <SDL.h>
#endif

static MainMenu menu;

int main(int argc, char *argv[]) {
    // Init game stuff
    //init();

    // Run game
    app(menu);

    return 0;
}
