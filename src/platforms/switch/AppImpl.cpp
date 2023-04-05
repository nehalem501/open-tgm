/* AppImpl.cpp - Switch */

#include "libswitch.h"
#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include <Deko3DGPU.h>

Size screen;
int tile_size = 9; // TODO

void app(Scene& scene) {
    // TODO detect screen size (can be different when docked)
    screen.width = 1280;
    screen.height = 720;

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    Deko3DGPU gpu;

    // TODO: Add to GPU interface
    load_textures();

    while (appletMainLoop()) {
        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    }
}
