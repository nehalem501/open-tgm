/* TargetTypes.h - PS3 */

#ifndef TARGET_TYPES_PS3_H
#define TARGET_TYPES_PS3_H

#include <stdint.h>
#include <stdio.h>

void empty_func(const char*, ...);
#define print printf

typedef uint16_t tiles_t;

#define tile_size 9 // TODO

#endif // TARGET_TYPES_PS3_H
