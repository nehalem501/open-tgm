/* AppImpl.cpp - PSP */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "resources/callbacks.h"
#include <glib2d.h>
#include <Global.h>
#include <Menu.h>
#include <Background.h>
#include <App.h>

#define VERS 1
#define REVS 0

PSP_MODULE_INFO("Open TGM", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER);
PSP_HEAP_SIZE_MAX();

g2dTexture *tileset_tex = NULL;
g2dTexture *outline_tex = NULL;
g2dTexture *frame_tex = NULL;
g2dTexture *digits_tex = NULL;
g2dTexture *labels_tex = NULL;
g2dTexture *text_tex = NULL;
g2dTexture *grades_tex = NULL;
g2dTexture *timer_tex = NULL;

#define printf pspDebugScreenPrintf

void app() {
    setupCallbacks();

    tileset_tex = g2dTexLoad("tilemap.png",G2D_SWIZZLE);
    outline_tex = g2dTexLoad("tilemap2.png",G2D_SWIZZLE);

    while (running()) {
        // Clear screen
        g2dClear(BLACK);

        // Process and draw a frame
        menu.update();
        background.draw();
        menu.draw();

        // Swap buffers and wait for VSYNC
        g2dFlip(G2D_VSYNC);
    }

    sceKernelExitGame();
}
