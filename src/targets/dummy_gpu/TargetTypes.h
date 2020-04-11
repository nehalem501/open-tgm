/* TargetTypes.h - dummy_gpu */

#ifndef TARGET_TYPES_DUMMY_GPU_H
#define TARGET_TYPES_DUMMY_GPU_H

#include <stdint.h>

void empty_func(const char*, ...);
#define print empty_func

typedef uint16_t tiles_t;

#endif // TARGET_TYPES_DUMMY_GPU_H
