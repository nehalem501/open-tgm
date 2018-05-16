/* AppImpl.cpp - PSP */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <pspgu.h>
#include "resources/callbacks.h"
//#include <glib2d.h>
#include <Global.h>
#include <MainMenu.h>
#include <Background.h>
#include <App.h>

#define VERS 0
#define REVS 1

PSP_MODULE_INFO("Open TGM", PSP_MODULE_USER, VERS, REVS);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_USER | THREAD_ATTR_VFPU);
//PSP_HEAP_SIZE_KB();

static unsigned int __attribute__((aligned(16))) list[524288];

/*g2dTexture *tileset_tex = NULL;
g2dTexture *outline_tex = NULL;
g2dTexture *frame_tex = NULL;
g2dTexture *digits_tex = NULL;
g2dTexture *labels_tex = NULL;
g2dTexture *text_tex = NULL;
g2dTexture *grades_tex = NULL;
g2dTexture *timer_tex = NULL;*/

void app() {
    setupCallbacks();

    #ifdef DEBUG
    pspDebugScreenInit();
    #endif

    sceGuInit();
    sceGuStart(GU_DIRECT, list);

    //g2dInit();

    // TODO
    // Init graphical assets
    init_graphics();

    /*tileset_tex = g2dTexLoad((char *) "resources/tilemap.png", G2D_SWIZZLE);
    outline_tex = g2dTexLoad((char *) "resources/tilemap2.png", G2D_SWIZZLE);
    text_tex = g2dTexLoad((char *) "resources/ui-font.png", G2D_SWIZZLE);
    frame_tex = g2dTexLoad((char *) "resources/frame.png", G2D_SWIZZLE);*/

    while (running()) {
        // Clear screen
        //g2dClear(BLACK);

        // Process and draw a frame
        //menu.update();
        //background.draw();
        //menu.draw();

        // Swap buffers and wait for VSYNC
        //g2dFlip(G2D_VSYNC);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }

    sceGuDisplay(GU_FALSE);
    sceGuTerm();

    sceKernelExitGame();
}
