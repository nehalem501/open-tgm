/* TargetTypes.h - Dummy */

#ifndef TARGET_TYPES_DUMMY_H
#define TARGET_TYPES_DUMMY_H

#include <stdint.h>

void empty_func(const char*, ...);
#define print empty_func

typedef uint16_t tiles_t;

#define tile_size 8

#endif // TARGET_TYPES_DUMMY_H
