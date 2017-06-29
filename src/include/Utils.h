/* Utils.h */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <Text.h>

inline int8_t modulo(int a, int n) { return (a % n + n) % n; }
//void sort(uint8_t array[], unsigned int length);
//void sort(int8_t array[], unsigned int length);
uint32_t tgm_random(uint32_t *state);
void edit_text(Text *text, int pos_x, int pos_y, int color, const char *str);

#endif
