/* TargetTypes.h - 3DS */

#ifndef TARGET_TYPES_3DS_H
#define TARGET_TYPES_3DS_H

#include <stdint.h>

#ifdef DEBUG
#include <stdio.h>
#define print printf
#endif

#include "lib3ds.h"

typedef uint32_t tiles_t;
typedef float gpu_float_t;
typedef C3D_Tex texture_t;

#endif
