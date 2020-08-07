/* TargetTypes.h - PSX */

#ifndef TARGET_TYPES_PSX_H
#define TARGET_TYPES_PSX_H

#include <stdint.h>

void empty_func(const char*, ...);
#define print empty_func

typedef uint16_t tiles_t;

#endif
