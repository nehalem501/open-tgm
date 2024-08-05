/* AppImpl.cpp - Dummy */

#include <Size.h>
#include <Scene.h>
#include <App.h>

Size screen = { 40, 30 }; // Size is in tiles

App::App() { }

void App::run(Scene& scene) {
    // For each frame {
        scene.update();
        scene.draw();
    // }
}
