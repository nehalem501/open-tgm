/* utils.h */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#include "utils.h"

inline int8_t modulo(int8_t a, int8_t n) { return (a % n + n) % n; }
void sort(uint8_t array[], unsigned int length);
void sort(int8_t array[], unsigned int length);
uint32_t tgm_random(uint32_t *state);

#endif
