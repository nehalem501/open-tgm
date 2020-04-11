/* main.cpp */

#include <Scene.h>
#include <App.h>

#ifdef TARGET_SDL
#include <SDL.h>
#endif

static Scene scene;

int main(int, char **) {
    // Init game stuff
    //init();

    // Run game
    app(scene);

    return 0;
}
