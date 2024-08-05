/* AppImpl.cpp - PSP */

#include <Scene.h>
#include <App.h>
#include <GPU.h>
#include <SceGuGPU.h>
#include "callbacks.h"
#include "pspsdk.h"

#define VERS 0
#define REVS 1

PSP_MODULE_INFO("Open TGM", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER | THREAD_ATTR_VFPU);

Size screen = { 480, 272 };

App::App() {
    setup_callbacks();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    static SceGuGPU gpu;
    gpu.load_textures();
    GPU::set_current(&gpu);
}

void App::run(Scene& scene) {
    GPU& gpu = GPU::get_current_mut();
    while (true) {
        scene.update();
        gpu.clear();
        scene.draw();
        gpu.display();
    }
}
