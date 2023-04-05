/* AppImpl.cpp - 3DS */

#include "lib3ds.h"
#include <Scene.h>
#include <GPU.h>
#include <N3DSGPU.h>
#include <App.h>

Size screen = { 400, 240 }; // TODO

void app(Scene& scene) {
    #ifdef DEBUG
    consoleDebugInit(debugDevice_SVC);
    #endif

    gfxInitDefault();
    N3DSGPU gpu(screen);

    // TODO: Add to GPU interface
	load_textures();

	//consoleInit(GFX_BOTTOM, NULL);

    // Main loop
    while (aptMainLoop()) {
        hidScanInput(); // Refresh Inputs

        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    }

    gfxExit();
}
