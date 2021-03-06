/* AppImpl.cpp - GBA */

#include <gba.h>
#include <Global.h>
#include <MainMenu.h>
#include <Background.h>
#include <App.h>

#define m_width 10
#define m_height 22
#include <cstring>

void VblankInterrupt() {
    // Clear screen
    memset((u16*) MAP_BASE_ADR(24), 0, sizeof(u16) * 32 * 20);

    /*u16 stack[m_width * m_height] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

        0 ,1, 2, 3, 4, 5, 6, 7, 8, 7,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        8, 9, 10, 11, 12, 13, 14, 15, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,

        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,

        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7
    };

    u16 *local_screen = (u16*) MAP_BASE_ADR(16) + 10;
    for (int i = 0; i < m_height - 2; i++) {
        memcpy(local_screen + 32 * i, stack + m_width * (i + 2), m_width * 2);
    }
    //local_screen[32 * 10] = 4;
    //local_screen[32 * 12] = 3;
    local_screen = (u16*) MAP_BASE_ADR(24) + 10;
    //local_screen[32 * 11] = 15;
    //local_screen[32 * 12] = 15;
    for (int i = 0; i < m_height - 2; i++) {
        memcpy(local_screen + 32 * i, stack + m_width * (i + 2), m_width * 2);
    }*/
    
    // Draw frame
    menu.draw();
}

void app() {
    // Set up the interrupt handlers
    irqInit();
    irqSet( IRQ_VBLANK, VblankInterrupt);

    // Enable Vblank Interrupt to allow VblankIntrWait
    irqEnable(IRQ_VBLANK);

    // Allow Interrupts
    REG_IME = 1;

    while (true) {
        // Do frame
        menu.update();

        // Wait for Vblank to draw
        VBlankIntrWait();
    }
}
