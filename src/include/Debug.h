/* Debug.h */

#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#include <stddef.h>
#include <stdint.h>
#include <Position.h>

//FILE *printd_out = stdout;

void printd_str(const char* str);

void printd_internal(const char* str);

void printd_internal(const bool value);

void printd_internal(void* pointer);
void printd_internal(const void* pointer);

void printd_internal(int8_t value);
void printd_internal(int16_t value);
void printd_internal(int32_t value);
void printd_internal(int64_t value);

void printd_internal(uint8_t value);
void printd_internal(uint16_t value);
void printd_internal(uint32_t value);
void printd_internal(uint64_t value);

void printd_internal(size_t value);

template<typename T, typename ... Args>
void printd_internal(T first, Args ... args) {
    printd_internal(first);
    printd_internal(args ...);
}

enum class DebugCategory: unsigned int {
    DEFAULT = 0,
    SYSTEM,
    INPUT,
    SCENE,
    SETTINGS,
    BACKGROUND,
    MODES,
    PLAYER,
    PLAYER_LOOP,
    SCORE,
    CREDIT_ROLL,
    GRAVITY,
    LOCK,
    CLEAR,
    DAS,
    FRAME,
    STACK,
    DIGITS,
    TEXT,
    TIMER,
    GPU,
    GPU_TILEMAP,
    GPU_TEXTURE,
    GPU_IMAGE,
    GPU_RECT,
    GPU_GLYPHS,
    GPU_VERTICES,
    NB_CATEGORIES
};

void printd_set_category_state(DebugCategory category, bool state);
bool printd_active_category(DebugCategory category);

template<typename ... Args>
void printd(DebugCategory category, Args ... args) {
    if (printd_active_category(category)) {
        printd_internal(args ...);
        printd_internal("\n"); // TODO
    }
}

#else
#define printd(fmt)
#endif // DEBUG

#endif // DEBUG_H
