/* AppImpl.cpp - 3DS */

#include "lib3ds.h"
#include <Scene.h>
#include <GPU.h>
#include <App.h>

Size screen = { 400, 240 }; // TODO

#define DISPLAY_TRANSFER_FLAGS \
	(GX_TRANSFER_FLIP_VERT(0) | GX_TRANSFER_OUT_TILED(0) | GX_TRANSFER_RAW_COPY(0) | \
	GX_TRANSFER_IN_FORMAT(GX_TRANSFER_FMT_RGBA8) | GX_TRANSFER_OUT_FORMAT(GX_TRANSFER_FMT_RGB8) | \
    GX_TRANSFER_SCALING(GX_TRANSFER_SCALE_NO))

void app(Scene& scene) {
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);

    // Initialize the render target
    C3D_RenderTarget *target = C3D_RenderTargetCreate(
		screen.height, // Swapped because framebuffer is rotated 90°
		screen.width,
		GPU_RB_RGBA8,
		GPU_RB_DEPTH24_STENCIL8);
    C3D_RenderTargetSetOutput(target, GFX_TOP, GFX_LEFT, DISPLAY_TRANSFER_FLAGS);

    init_gpu();
	load_textures();

	//consoleInit(GFX_BOTTOM, NULL);

    // Main loop
    while (aptMainLoop()) {
        hidScanInput(); // Refresh Inputs

        // Process one frame
        scene.update();

        // Draw
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C3D_RenderTargetClear(target, C3D_CLEAR_ALL, 0x000000FF, 0);
		C3D_FrameDrawOn(target);

        scene.draw();

		C3D_FrameEnd(0);
    }

	free_gpu();

	// Deinitialize graphics
    C3D_Fini();
    gfxExit();
}
