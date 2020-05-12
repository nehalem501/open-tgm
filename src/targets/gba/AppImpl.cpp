/* AppImpl.cpp - GBA */

#include <gba.h>
#include <Size.h>
#include <Global.h>
#include <Scene.h>
#include <Background.h>
#include <App.h>

#define m_width 10
#define m_height 22
#include <cstring>

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

    main_scene = &scene;

    while (true) {
        // Do frame
        scene.update();

        // Wait for Vblank to draw
        VBlankIntrWait();
    }
}
