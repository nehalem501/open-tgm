/* AppImpl.cpp - PSP */

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include <pspgu.h>
#include "resources/callbacks.h"
#include "resources/vram.h"
//#include <glib2d.h>
#include <Global.h>
#include <GlobalPSP.h>
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

    void* fbp0 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    void* fbp1 = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_8888);
    void* zbp = getStaticVramBuffer(BUF_WIDTH,SCR_HEIGHT,GU_PSM_4444);

    sceGuStart(GU_DIRECT, list);

    sceGuDrawBuffer(GU_PSM_8888, fbp0, BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH, SCR_HEIGHT, fbp1, BUF_WIDTH);
    sceGuDepthBuffer(zbp, BUF_WIDTH);

    sceGuOffset(2048 - (SCR_WIDTH / 2), 2048 - (SCR_HEIGHT / 2));
    sceGuViewport(2048, 2048, SCR_WIDTH, SCR_HEIGHT);

    sceGuDepthRange(65535, 0);
    sceGuClearDepth(65535);
    sceGuDepthFunc(GU_LEQUAL);

    sceGuAlphaFunc(GU_GREATER, 0, 255);
    sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
    sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
    sceGuTexFilter(GU_LINEAR, GU_LINEAR);
    sceGuShadeModel(GU_SMOOTH);

    sceGuEnable(GU_DEPTH_TEST);
    sceGuEnable(GU_ALPHA_TEST);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuEnable(GU_BLEND);

    sceGuDisable(GU_CULL_FACE);
    sceGuDisable(GU_CLIP_PLANES);
    sceGuDisable(GU_DITHER);

    sceGuScissor(0, 0, SCR_WIDTH, SCR_HEIGHT);

    sceGuFinish();
    sceGuSync(0, 0);

    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);


    //g2dInit();

    // TODO
    // Init graphical assets
    init_graphics();

    /*tileset_tex = g2dTexLoad((char *) "resources/tilemap.png", G2D_SWIZZLE);
    outline_tex = g2dTexLoad((char *) "resources/tilemap2.png", G2D_SWIZZLE);
    text_tex = g2dTexLoad((char *) "resources/ui-font.png", G2D_SWIZZLE);
    frame_tex = g2dTexLoad((char *) "resources/frame.png", G2D_SWIZZLE);*/

    while (running()) {
        sceGuStart(GU_DIRECT,list);

        // Clear screen
        sceGuClearColor(0xff554433); // TODO change to black when everything works
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

        // Process and draw a frame
        //menu.update();
        //background.draw();
        //menu.draw();
        
        sceGuFinish();
        sceGuSync(0,0);

        // Swap buffers and wait for VSYNC
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }

    sceGuDisplay(GU_FALSE);
    sceGuTerm();

    sceKernelExitGame();
}
