/* timing.h - SDL */

#ifndef TIMING_SDL_H
#define TIMING_SDL_H

#include <stdint.h>

void sleep_usecs(uint64_t usecs);
uint64_t get_time_usecs();

#endif
