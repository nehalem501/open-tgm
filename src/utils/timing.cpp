/* timing.cpp - SDL */

#include <stdint.h>
#include <TargetTypes.h>
#include "timing.h"

#ifdef _WIN32
/* Windows Implementation */

#include <windows.h>

static LARGE_INTEGER get_frequency() {
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return frequency;
}

static bool is_xp_or_older() {
    return static_cast<DWORD>(LOBYTE(LOWORD(GetVersion()))) < 6;
}

uint64_t get_time_usecs() {
    static LARGE_INTEGER frequency = get_frequency();
    static bool old_windows = is_xp_or_older();

    CRITICAL_SECTION mutex;
    LARGE_INTEGER time;

    if (old_windows) {
        InitializeCriticalSection(&mutex);
        EnterCriticalSection(&mutex);
        QueryPerformanceCounter(&time);
        LeaveCriticalSection(&mutex);
    } else {
        QueryPerformanceCounter(&time);
    }

    return (1000000 * time.QuadPart / frequency.QuadPart)
}

void sleep_usecs(uint64_t usecs) {
    TIMECAPS tc;
    timeGetDevCaps(&tc, sizeof(TIMECAPS));

    timeBeginPeriod(tc.wPeriodMin);
    Sleep(usecs / 1000);
    timeEndPeriod(tc.wPeriodMin);
}

#endif /* _WIN32 */

#ifdef __APPLE__
/* macOS & iOS Implementation */

#include <mach/mach_time.h>

uint64_t get_time_usecs() {
    static mach_timebase_info_data_t frequency = {0, 0};
    if (frequency.denom == 0)
        mach_timebase_info(&frequency);

    uint64_t nanosecs = mach_absolute_time() * frequency.numer / frequency.denom;

    return nanosecs / 1000;
}

#endif /* __APPLE__ */

#if (defined(__unix__) || defined(__unix)) && !defined(__APPLE__)
/* POSIX Implementation */

#include <time.h>

uint64_t get_time_usecs() {
    timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    return ((uint64_t) time.tv_sec * 1000000 + (uint64_t) time.tv_nsec / 1000);
}
#endif /* (defined(__unix__) || defined(__unix)) && !defined(__APPLE__) */

#if defined(__unix__) || defined(__unix) || defined(__APPLE__)
/* POSIX Implementation (including macOS & iOS) */

#include <errno.h>
#include <time.h>

void sleep_usecs(uint64_t usecs) {
    timespec ti;
    ti.tv_nsec = (usecs % 1000000) * 1000;
    ti.tv_sec = usecs / 1000000;

    while ((nanosleep(&ti, &ti) == -1) && (errno == EINTR)) {
        #ifdef DEBUG
        print("nanosleep() == EINTR");
        #endif
    }
}

#endif /* defined(__unix__) || defined(__unix) || defined(__APPLE__) */

