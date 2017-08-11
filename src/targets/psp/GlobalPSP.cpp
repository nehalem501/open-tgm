/* GlobalPSP.cpp - PSP */

#include <glib2d.h>
#include "GlobalPSP.h"

void set_tile_piece(int tile) {
    switch (tile) {
        case 1:
            g2dSetCropXY(0, 0);
            break;

        case 2:
            g2dSetCropXY(10, 0);
            break;

        case 3:
            g2dSetCropXY(20, 0);
            break;

        case 4:
            g2dSetCropXY(30, 0);
            break;

        case 5:
            g2dSetCropXY(0, 10);
            break;

        case 6:
            g2dSetCropXY(10, 10);
            break;

        case 7:
            g2dSetCropXY(20, 10);
            break;

        case 8:
            g2dSetCropXY(30, 10);
            break;
    }
}

void set_tile_outline(int tile) {
    switch (tile) {
        case 0x01:
            g2dSetCropXY(10, 0);
            break;

        case 0x02:
            g2dSetCropXY(20, 0);
            break;

        case 0x03:
            g2dSetCropXY(30, 0);
            break;

        case 0x04:
            g2dSetCropXY(0, 10);
            break;

        case 0x05:
            g2dSetCropXY(10, 10);
            break;

        case 0x06:
            g2dSetCropXY(20, 10);
            break;

        case 0x07:
            g2dSetCropXY(30, 10);
            break;

        case 0x08:
            g2dSetCropXY(0, 20);
            break;

        case 0x09:
            g2dSetCropXY(10, 20);
            break;

        case 0x0A:
            g2dSetCropXY(20, 20);
            break;

        case 0x0B:
            g2dSetCropXY(30, 20);
            break;

        case 0x0C:
            g2dSetCropXY(0, 30);
            break;

        case 0x0D:
            g2dSetCropXY(10, 30);
            break;

        case 0x0E:
            g2dSetCropXY(20, 30);
            break;

        case 0x0F:
            g2dSetCropXY(30, 30);
            break;
    }
}
