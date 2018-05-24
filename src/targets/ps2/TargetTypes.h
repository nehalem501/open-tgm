/* TargetTypes.h - PS2 */

#ifndef TARGET_TYPES_PS2_H
#define TARGET_TYPES_PS2_H

#include <tamtypes.h>

typedef s8 int8_t;
typedef s16 int16_t;
typedef s32 int32_t;
typedef u8 uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;

void empty_func(const char*, ...);
#define print empty_print

typedef uint16_t tiles_t;

#endif
