/* TargetTypes.h - PSP */

#ifndef TARGET_TYPES_PSP_H
#define TARGET_TYPES_PSP_H

#include <stdint.h>

void empty_func(const char*, ...);

#ifdef DEBUG
#include <pspdebug.h>
#define print pspDebugScreenPrintf
#endif

typedef unsigned int tiles_t;

#define tile_size 10

#endif // TARGET_TYPES_PSP_H
