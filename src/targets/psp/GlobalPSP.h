/* GlobalPSP.h - PSP */

#ifndef GLOBAL_PSP_H
#define GLOBAL_PSP_H

#include <glib2d.h>

struct vertex {
    float x, y;
};

struct quad {
    vertex verts[4];
    int tex_x, tex_y;
    int tex_w, tex_h;
};

extern g2dTexture *tileset_tex;
extern g2dTexture *outline_tex;
extern g2dTexture *frame_tex;
extern g2dTexture *digits_tex;
extern g2dTexture *labels_tex;
extern g2dTexture *text_tex;
extern g2dTexture *grades_tex;
extern g2dTexture *timer_tex;

#endif // GLOBAL_PSP_H
