/* AppImpl.cpp - PSP */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "resources/callbacks.h"
#include <Global.h>
#include <Menu.h>
#include <Background.h>
#include <App.h>

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("Open TGM", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

#define printf pspDebugScreenPrintf

void app() {
    setupCallbacks();

    while (running()) {
        // Do frame
        menu.update();
        background.draw();
        menu.draw();

        // TODO VBLANK
    }

    sceKernelExitGame();
}
