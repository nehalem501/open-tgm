/* timing.h - SDL2 */

#ifndef TIMING_SDL2_H
#define TIMING_SDL2_H

#include <stdint.h>

void sleep_usecs(uint64_t usecs);
uint64_t get_time_usecs();

#endif
