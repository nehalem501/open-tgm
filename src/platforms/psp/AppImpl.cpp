/* AppImpl.cpp - PSP */

#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include "callbacks.h"
#include "pspsdk.h"

#define VERS 0
#define REVS 1

PSP_MODULE_INFO("Open TGM", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER | THREAD_ATTR_VFPU);

Size screen = { 480, 272 };

void app(Scene& scene) {
    setup_callbacks();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    init_gpu();
    load_textures();

    while (true) {
        scene.update();
        graphics_clear();
        scene.draw();
        graphics_display();
    }

    free_gpu();
}
