/* TargetTypes.h - PSP */

#ifndef TARGET_TYPES_PSP_H
#define TARGET_TYPES_PSP_H

#include <stddef.h>
#include <stdint.h>

void empty_func(const char*, ...);

#ifdef DEBUG
#include <pspdebug.h>
#define print pspDebugScreenPrintf
#endif

namespace Global {
    constexpr int tile_size = 10;
}

#endif // TARGET_TYPES_PSP_H
