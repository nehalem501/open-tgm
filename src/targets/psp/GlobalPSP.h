/* GlobalPSP.h - PSP */

#ifndef GLOBAL_PSP_H
#define GLOBAL_PSP_H

#include <stdint.h>
#include <glib2d.h>

extern g2dTexture *tileset_tex;
extern g2dTexture *outline_tex;
extern g2dTexture *frame_tex;
extern g2dTexture *digits_tex;
extern g2dTexture *labels_tex;
extern g2dTexture *text_tex;
extern g2dTexture *grades_tex;
extern g2dTexture *timer_tex;

void set_tile_piece(int tile);
void set_tile_outline(int tile);

#endif // GLOBAL_PSP_H
