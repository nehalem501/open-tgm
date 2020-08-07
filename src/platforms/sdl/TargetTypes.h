/* TargetTypes.h - SDL */

#ifndef TARGET_TYPES_SDL_H
#define TARGET_TYPES_SDL_H

#include <stdint.h>

#ifdef DEBUG
#include <stdio.h>
#define print printf
#endif

typedef uint16_t tiles_t;

extern int tile_size;

#endif // TARGET_TYPES_SDL_H
