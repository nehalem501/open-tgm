/* globalImpl.cpp - GBA */

#include <cstring>
#include <gba.h>
#include <resources/tilemap.h>
#include <resources/outline.h>
#include <resources/shared.h>
#include <Global.h>

void init_random() {
}

void init_textures() {
    // Set mode 0 and enable background 0
    SetMode(MODE_0 | BG0_ON | BG1_ON);

    //REG_BG0CNT = BG_CBB(0) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
    REG_BG0CNT = TILE_BASE(1) | MAP_BASE(24) | BG_256_COLOR | TEXTBG_SIZE_256x256;
    REG_BG1CNT = TILE_BASE(0) | MAP_BASE(16) | BG_256_COLOR | TEXTBG_SIZE_256x256;

    // Load tilemap and it's palette into VRAM
    dmaCopy(tilemapTiles, TILE_BASE_ADR(0), tilemapTilesLen);
    dmaCopy(sharedPal, BG_PALETTE, sharedPalLen);

    dmaCopy(outlineTiles, TILE_BASE_ADR(1), outlineTilesLen);
    //dmaCopy(outline_pal, BG_PALETTE + TILEMAP_PAL_LEN,  OUTLINE_PAL_LEN);
    /* We need the same palette for all tilemaps */
    /* TODO palette generation taking into acount both tilemaps */
}
