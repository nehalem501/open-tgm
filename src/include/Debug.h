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

void printd_internal(char value);
void printd_internal(short value);
void printd_internal(int value);
void printd_internal(long value);
void printd_internal(long long value);

void printd_internal(unsigned char value);
void printd_internal(unsigned short value);
void printd_internal(unsigned int value);
void printd_internal(unsigned long value);
void printd_internal(unsigned long long value);

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
