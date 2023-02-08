/* AppImpl.cpp - Switch */

#include "libswitch.h"
#include <Scene.h>
#include <App.h>
#include <GPU.h>

Size screen;
int tile_size = 9; // TODO

void app(Scene& scene) {
    // TODO detect screen size
    screen.width = 1280;
    screen.height = 720;

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    init_gpu();
    load_textures();

    while (appletMainLoop()) {
        scene.update();
        graphics_clear();
        scene.draw();
        graphics_display();
    }

    free_gpu();
}
