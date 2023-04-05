/* main.cpp */

#include <Utils.h>
#include <Scene.h>
#include <App.h>

#ifdef TARGET_SDL
#include <SDL.h>
#endif

int main(int argc, char** argv) {
    parse_args(argc, argv);

    // Run game
    static Scene scene;
    app(scene);

    return 0;
}


