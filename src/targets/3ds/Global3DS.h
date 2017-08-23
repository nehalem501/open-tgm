/* Global3DS.h - 3DS */

#ifndef GLOBAL_3DS_H
#define GLOBAL_3DS_H

#include <3ds.h>
#include <citro3d.h>

extern C3D_Tex background_tex;
//extern C3D_Tex tileset_tex;
//extern C3D_Tex outline_tex;
extern C3D_Tex frame_tex;
//extern C3D_Tex digits_tex;
//extern C3D_Tex labels_tex;
extern C3D_Tex text_tex;
//extern C3D_Tex grades_tex;
//extern C3D_Tex timer_tex;

struct vertex {
    float x, y;
    float u, v;
    float r, g, b, a;
};

struct quad {
    vertex verts[4];
};

#endif
