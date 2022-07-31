/* Mode.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Grade.h>
#include <Debug.h>
#include <Mode.h>

Mode::Mode(const RawMode *raw_mode) : m_mode(raw_mode) {
    printd(DebugCategory::MODES, "Mode constructor: ", raw_mode->name);
}

unsigned int Mode::are(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->are_nb; i++) {
        if (level >= m_mode->are[i].level) {
            last = i;
        }

        if (level < m_mode->are[i].level) {
            break;
        }
    }

    return m_mode->are[last].value;
}

unsigned int Mode::line_are(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->line_are_nb; i++) {
        if (level >= m_mode->line_are[i].level) {
            last = i;
        }

        if (level < m_mode->line_are[i].level) {
            break;
        }
    }

    return m_mode->line_are[last].value;
}

unsigned int Mode::das(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->das_nb; i++) {
        if (level >= m_mode->das[i].level) {
            last = i;
        }

        if (level < m_mode->das[i].level) {
            break;
        }
    }

    return m_mode->das[last].value;
}

unsigned int Mode::lock(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->lock_nb; i++) {
        if (level >= m_mode->lock[i].level) {
            last = i;
        }

        if (level < m_mode->lock[i].level) {
            break;
        }
    }

    return m_mode->lock[last].value;
}

unsigned int Mode::clear(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->clear_nb; i++) {
        if (level >= m_mode->clear[i].level) {
            last = i;
        }

        if (level < m_mode->clear[i].level) {
            break;
        }
    }

    return m_mode->clear[last].value;
}

unsigned int Mode::gravity(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_mode->gravity_nb; i++) {
        if (level >= m_mode->gravity[i].level) {
            last = i;
        }

        if (level < m_mode->gravity[i].level) {
            break;
        }
    }

    return m_mode->gravity[last].value;
}

unsigned int Mode::section(unsigned int level) {
    if (m_mode->section) {
        for (unsigned int i = 100; i < m_mode->max_level; i += 100) {
            if (level < i) {
                return i;
            }
        }
    }

    return m_mode->max_level;
}
