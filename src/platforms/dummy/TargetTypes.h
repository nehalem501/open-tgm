/* TargetTypes.h - Dummy */

#ifndef TARGET_TYPES_DUMMY_H
#define TARGET_TYPES_DUMMY_H

#include <stddef.h>
#include <stdint.h>

void empty_func(const char*, ...);
#define print empty_func

namespace Global {
    constexpr int tile_size = 8;
}

#endif // TARGET_TYPES_DUMMY_H
