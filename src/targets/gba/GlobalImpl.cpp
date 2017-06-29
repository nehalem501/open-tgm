/* globalImpl.cpp - GBA */

#include <cstring>
#include <gba.h>
#include <resources/tilemap.h>
#include <Global.h>

void initRandom() {
}

void initTextures() {
    // Set mode 0 and enable background 0
    SetMode(MODE_0 | BG0_ON);

    // Load tilemap palette into VRAM
    memcpy(BG_PALETTE, tilemap_pal, TILEMAP_PAL_LEN);
}
