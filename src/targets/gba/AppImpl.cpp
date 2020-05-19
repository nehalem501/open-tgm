/* AppImpl.cpp - GBA */

#include <gba.h>
#include <Size.h>
#include <Global.h>
#include <Scene.h>
#include <Background.h>
#include <resources/fulltilemap.h>
#include <App.h>

#define m_width 10
#define m_height 22

Size screen = { 30, 20 }; // Size is in tiles

static Scene *main_scene;

void VblankInterrupt() {
    // Clear screen
    memset((u16*) MAP_BASE_ADR(24), 0, sizeof(u16) * 32 * 20);
    
    // Draw frame
    main_scene->draw();
}

void app(Scene& scene) {
    // Set up the interrupt handlers
    irqInit();
    irqSet( IRQ_VBLANK, VblankInterrupt);

    // Enable Vblank Interrupt to allow VblankIntrWait
    irqEnable(IRQ_VBLANK);

    // Allow Interrupts
    REG_IME = 1;

    // Set mode 0 and enable background 0
    SetMode(MODE_0 | BG0_ON | BG1_ON);

    //REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
    REG_BG0CNT = TILE_BASE(1) | MAP_BASE(24) | BG_256_COLOR | TEXTBG_SIZE_256x256;
    REG_BG1CNT = TILE_BASE(0) | MAP_BASE(16) | BG_256_COLOR | TEXTBG_SIZE_256x256;

    // Load tilemap and it's palette into VRAM
    dmaCopy(fulltilemapTiles, TILE_BASE_ADR(0), fulltilemapTilesLen);
    dmaCopy(fulltilemapPal, BG_PALETTE, fulltilemapPalLen);

    main_scene = &scene;

    while (true) {
        // Do frame
        scene.update();

        // Wait for Vblank to draw
        VBlankIntrWait();
    }
}
