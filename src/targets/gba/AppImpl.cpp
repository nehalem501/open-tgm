/* AppImpl.cpp - GBA */

#include <gba.h>
#include <Global.h>
#include <Menu.h>
#include <Background.h>
#include <App.h>

void VblankInterrupt() {
    // Do frame
    menu.update();
    background.draw();
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
        VBlankIntrWait();
    }
}
