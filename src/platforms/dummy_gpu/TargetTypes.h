/* TargetTypes.h - dummy_gpu */

#ifndef TARGET_TYPES_DUMMY_GPU_H
#define TARGET_TYPES_DUMMY_GPU_H

#include <stdint.h>
#include <stdio.h>

void empty_func(const char*, ...);
#define print printf

typedef uint16_t tiles_t;

#define tile_size 8

#endif // TARGET_TYPES_DUMMY_GPU_H
