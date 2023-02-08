/* main.cpp */

#include <Utils.h>
#include <Scene.h>
#include <App.h>

#ifdef TARGET_SDL
#include <SDL.h>
#endif

static Scene scene;

int main(int argc, char** argv) {
    // Init game stuff
    //init();
    parse_args(argc, argv);

    // Run game
    app(scene);

    return 0;
}


