/* AppImpl.cpp - Switch */

#include "libswitch.h"
#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include <Deko3DGPU.h>

Size screen;
int tile_size = 9; // TODO

App::App() {
    // TODO detect screen size (can be different when docked)
    screen.width = 1280;
    screen.height = 720;

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    static Deko3DGPU gpu;
    gpu.load_textures();
    GPU::set_current(&gpu);
}

void App::run(Scene& scene) {
    GPU& gpu = GPU::get_current_mut();
    while (appletMainLoop()) {
        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    }
}
