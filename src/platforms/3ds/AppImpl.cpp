/* AppImpl.cpp - 3DS */

#include "lib3ds.h"
#include <Scene.h>
#include <GPU.h>
#include <Citro3DGPU.h>
#include <App.h>

Size screen = { 400, 240 }; // TODO

App::App() {
    #ifdef DEBUG
    consoleDebugInit(debugDevice_SVC);
    #endif

    static Citro3DGPU gpu(screen);
    gpu.load_textures();
    GPU::set_current(&gpu);
}

void App::run(Scene& scene) {
    GPU& gpu = GPU::get_current_mut();

    //consoleInit(GFX_BOTTOM, NULL);

    // Main loop
    while (aptMainLoop()) {
        hidScanInput(); // Refresh Inputs

        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    }
}
