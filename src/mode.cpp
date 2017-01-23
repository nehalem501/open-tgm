/* mode.cpp */

#include <stdint.h>
#include "mode.h"

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

