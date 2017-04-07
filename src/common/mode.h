/* mode.h */

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
        
        struct Timing* gravity;
        struct Timing* are;
        struct Timing* line_are;
        struct Timing* das;
        struct Timing* lock;
        struct Timing* clear;
        
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
