/* Mode.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Grade.h>
#include <Debug.h>
#include <Mode.h>

Mode::Mode(const RawMode *raw_mode) : m_mode(raw_mode) {
    printd(DebugCategory::MODES, "Mode constructor: ", raw_mode ? raw_mode->name : "NULL");
}

unsigned int Mode::get_timing(
    const Timing* timings,
    const unsigned int nb,
    const unsigned int level) const
{
    unsigned int last = 0;

    for (unsigned int i = 0; i < nb; i++) {
        if (level >= timings[i].level) {
            last = i;
        }

        if (level < timings[i].level) {
            break;
        }
    }

    return timings[last].value;
}

unsigned int Mode::section(unsigned int level) const {
    if (m_mode->section) {
        for (unsigned int i = 100; i < m_mode->max_level; i += 100) {
            if (level < i) {
                return i;
            }
        }
    }

    return m_mode->max_level;
}
