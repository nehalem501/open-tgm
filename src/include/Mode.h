/* Mode.h */

#ifndef MODE_H
#define MODE_H

#include <stdint.h>

enum {
    GRADE_9 = 0,
    GRADE_8,
    GRADE_7,
    GRADE_6,
    GRADE_5,
    GRADE_4,
    GRADE_3,
    GRADE_2,
    GRADE_1,
    GRADE_S1,
    GRADE_S2,
    GRADE_S3,
    GRADE_S4,
    GRADE_S5,
    GRADE_S6,
    GRADE_S7,
    GRADE_S8,
    GRADE_S9,
    GRADE_GM,
    GRADE_MAX_NB
};

enum {
    CREDITS_REQUIRED,
    CREDITS_PLAYABLE,
    NO_CREDITS
};

struct Timing {
    unsigned int level;
    unsigned int value;
};

struct Label {
    char *string;
    int8_t x;
    int8_t y;
};

struct Position {
    int8_t x;
    int8_t y;
};

class Mode {
    public:
        const char* name;

        bool sonic_drop;
        bool display_score;
        bool section;
        //bool line_are_test;

        unsigned int size_x, size_y;
        unsigned int max_level;

        unsigned int gravity_nb;
        unsigned int are_nb;
        unsigned int line_are_nb;
        unsigned int das_nb;
        unsigned int lock_nb;
        unsigned int clear_nb;
	    unsigned int labels_nb;

        struct Timing* gravity;
        struct Timing* are;
        struct Timing* line_are;
        struct Timing* das;
        struct Timing* lock;
        struct Timing* clear;

        struct Label* labels;

        struct Position score_pos;
        struct Position level_pos;
        struct Position level_target_pos;

        Mode(const char* nm, bool s_drop, bool disp_score, bool sec,
             unsigned int sz_x, unsigned int sz_y, unsigned int max_lvl,
             struct Timing* t_gravity, unsigned int grav_nb,
             struct Timing* t_are, unsigned int are_n,
             struct Timing* t_line_are, unsigned int ln_are_n,
             struct Timing* t_das, unsigned int das_n,
             struct Timing* t_lock, unsigned int lock_n,
             struct Timing* t_clear, unsigned int clr_n,
             struct Label* l, unsigned int l_nb, struct Position scr_pos,
             struct Position lvl_pos, struct Position lvl_tg_pos);

        unsigned int getSizeX();
        unsigned int getSizeY();

        bool displayScore();
        bool sonicDrop();

        unsigned int getARE(unsigned int level);
        unsigned int getLineARE(unsigned int level);
        unsigned int getDAS(unsigned int level);
        unsigned int getLock(unsigned int level);
        unsigned int getClear(unsigned int level);
        unsigned int getGravity(unsigned int level);
        unsigned int getSection(unsigned int level);
};

#endif
