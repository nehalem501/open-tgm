/* main.cpp */

#include <Utils.h>
#include <Scene.h>
#include <App.h>

#ifdef TARGET_SDL
#include <SDL.h>
#endif

int main(int argc, char** argv) {
    parse_args(argc, argv);

    App app;

    // Run game
    static Scene scene(screen);
    app.run(scene);

    return 0;
}
