/* TargetTypes.h - dummy_gpu */

#ifndef TARGET_TYPES_DUMMY_GPU_H
#define TARGET_TYPES_DUMMY_GPU_H

#include <stdint.h>
#include <stddef.h>

typedef uint16_t tiles_t;

namespace Global {
    constexpr int tile_size = 8;
}

#endif // TARGET_TYPES_DUMMY_GPU_H
