/* mode.cpp */

#include <stdint.h>
#include "mode.h"

Mode::Mode(const char* nm, bool s_drop, bool disp_score, bool sec,
           unsigned int sz_x, unsigned int sz_y, unsigned int max_lvl,
           struct Timing* t_gravity, unsigned int grav_nb,
           struct Timing* t_are, unsigned int are_n,
           struct Timing* t_line_are, unsigned int ln_are_n,
           struct Timing* t_das, unsigned int das_n,
           struct Timing* t_lock, unsigned int lock_n,
           struct Timing* t_clear, unsigned int clr_n) : 
    name(nm), sonic_drop(s_drop), display_score(disp_score), section(sec),
    size_x(sz_x), size_y(sz_y), max_level(max_lvl), gravity_nb(grav_nb),
    are_nb(are_n), line_are_nb(ln_are_n), das_nb(das_n), lock_nb(lock_n),
    clear_nb(clr_n), gravity(), are(), line_are(), das(), lock(), clear() {
}

unsigned int Mode::getSizeX() {
    return size_x;
}

unsigned int Mode::getSizeY() {
    return size_y;
}

bool Mode::displayScore() {
    return display_score;
}

bool Mode::sonicDrop() {
    return sonic_drop;
}

unsigned int Mode::getARE(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < are_nb; i++) {
        if (level >= are[i].level) {
            last = i;
        }

        if (level < are[i].level) {
            break;
        }
    }

    return are[last].value;
}

unsigned int Mode::getLineARE(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < line_are_nb; i++) {
        if (level >= line_are[i].level) {
            last = i;
        }

        if (level < line_are[i].level) {
            break;
        }
    }

    return line_are[last].value;
}

unsigned int Mode::getDAS(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < das_nb; i++) {
        if (level >= das[i].level) {
            last = i;
        }

        if (level < das[i].level) {
            break;
        }
    }

    return das[last].value;
}

unsigned int Mode::getLock(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < lock_nb; i++) {
        if (level >= lock[i].level) {
            last = i;
        }

        if (level < lock[i].level) {
            break;
        }
    }

    return lock[last].value;
}

unsigned int Mode::getClear(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < clear_nb; i++) {
        if (level >= clear[i].level) {
            last = i;
        }

        if (level < clear[i].level) {
            break;
        }
    }

    return clear[last].value;
}

unsigned int Mode::getGravity(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < gravity_nb; i++) {
        if (level >= gravity[i].level) {
            last = i;
        }

        if (level < gravity[i].level) {
            break;
        }
    }

    return gravity[last].value;
}

unsigned int Mode::getSection(unsigned int level) {
    if (section) {
        for (unsigned int i = 100; i < max_level; i += 100) {
            if (level < i) {
                return i;
            }
        }
    }

    return max_level;
}