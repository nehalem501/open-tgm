/* TargetTypes.h - SDL2 */

#ifndef TARGET_TYPES_SDL2_H
#define TARGET_TYPES_SDL2_H

#include <stdint.h>

#ifdef DEBUG
#include <stdio.h>
#define print printf
#endif

typedef uint16_t tiles_t;

extern int tile_size;

#endif
