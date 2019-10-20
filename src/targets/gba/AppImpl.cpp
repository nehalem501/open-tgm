/* AppImpl.cpp - GBA */

#include <gba.h>
#include <Global.h>
#include <MainMenu.h>
#include <Background.h>
#include <App.h>

#define m_width 10
#define m_height 22
#include <cstring>

static MainMenu *main_menu;

void VblankInterrupt() {
    // Clear screen
    memset((u16*) MAP_BASE_ADR(24), 0, sizeof(u16) * 32 * 20);
    
    // Draw frame
    main_menu->draw();
}

void app(MainMenu& menu) {
    // Set up the interrupt handlers
    irqInit();
    irqSet( IRQ_VBLANK, VblankInterrupt);

    // Enable Vblank Interrupt to allow VblankIntrWait
    irqEnable(IRQ_VBLANK);

    // Allow Interrupts
    REG_IME = 1;

    main_menu = &menu;

    while (true) {
        // Do frame
        menu.update();

        // Wait for Vblank to draw
        VBlankIntrWait();
    }
}
