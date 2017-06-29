/* Utils.cpp */

#include <stdint.h>
#include <Utils.h>

/*
// TODO more efficient
void sort(uint8_t array[], unsigned int length) {
    uint8_t temp;
    for (unsigned int i = 0; i < (length - 1); i++) {
        for (unsigned int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void sort(int8_t array[], unsigned int length) {
    int8_t temp;
    for (unsigned int i = 0; i < (length - 1); i++) {
        for (unsigned int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}*/

uint32_t tgm_random(uint32_t *state) {
    static const uint32_t m = 0x41C64E6Dul;
    static const uint32_t c = 0x3039ul;
    *state = *state * m + c;
    static const uint32_t mask = 0x7FFFUL;
    return (*state >> 10) & mask;
}
