/* RawMode.h */

#ifndef RAW_MODE_H
#define RAW_MODE_H

#include <TargetTypes.h>
#include <Grade.h>
#include <CreditRoll.h>

struct Timing {
    const unsigned int level;
    const unsigned int value;
};

struct Label {
    const char *string;
    const int8_t x;
    const int8_t y;
};

struct DigitsPosition {
    const int8_t x;
    const int8_t y;
};

struct RawMode {
    const char* name;

    const bool sonic_drop;
    const bool display_score;
    const bool section;
    const bool keep_down;
    const bool old_locking_style;

    const uint8_t frame_color;

    const unsigned int credit_roll;

    const unsigned int width, height;
    const unsigned int max_level;
    const unsigned int initial_grade;
    const unsigned int randomtries;

    const struct Timing* gravity;
    const unsigned int gravity_nb;

    const struct Timing* are;
    const unsigned int are_nb;

    const struct Timing* line_are;
    const unsigned int line_are_nb;

    const struct Timing* das;
    const unsigned int das_nb;

    const struct Timing* lock;
    const unsigned int lock_nb;

    const struct Timing* clear;
    const unsigned int clear_nb;

    const struct Label* labels;
    const unsigned int labels_nb;

    const struct DigitsPosition score_pos;
    const struct DigitsPosition level_pos;
    const struct DigitsPosition level_target_pos;

    uint32_t (*const score_func)(
        uint32_t, uint32_t, uint32_t, uint32_t,
        uint32_t, uint32_t, uint32_t, uint32_t);
    void (*const grade_func)(uint32_t, unsigned int, Grade *grade);
};

#endif // RAW_MODE_H
