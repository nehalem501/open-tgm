/* Utils.cpp */

#include <stdint.h>
#include <Text.h>
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

void edit_text(Text *text, int pos_x, int pos_y, int color, const char *str) {
    text->update_text(str);
    text->update_pos(pos_x, pos_y);
    text->update_graphics();
    text->update_color(color);
}

void set_button_state(bool state, Text *text) {
    if (state) {
        text->update_text("ON");
        text->update_graphics();
        text->update_color(TextColor::YELLOW);
    } else {
        text->update_text("OFF");
        text->update_graphics();
        text->update_color(TextColor::TRANSPARENT);
    }
}
