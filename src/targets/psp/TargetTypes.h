/* TargetTypes.h - PSP */

#ifndef TARGET_TYPES_PSP_H
#define TARGET_TYPES_PSP_H

#ifdef DEBUG
#include <pspdebug.h>
#define print pspDebugScreenPrintf
#endif

typedef unsigned int tiles_t;

struct vertex {
    float x, y;
    uint32_t color;
};

struct quad {
    vertex verts[4];
    int tex_x, tex_y;
    int tex_w, tex_h;
};

#endif
