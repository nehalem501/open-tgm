/* Mode.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Grade.h>
#include <Mode.h>

Mode::Mode(
    const char* name,
    const bool sonic_drop,
    const bool display_score,
    const bool section,
    const bool keep_down,
    const bool old_locking_style,
    const unsigned int credit_roll,
    const unsigned int width,
    const unsigned int height,
    const unsigned int max_level,
    const unsigned int initial_grade,
    const unsigned int random_tries,
    const struct Timing* gravity, const unsigned int gravity_nb,
    const struct Timing* are, const unsigned int are_nb,
    const struct Timing* line_are, const unsigned int line_are_nb,
    const struct Timing* das, const unsigned int das_nb,
    const struct Timing* lock, const unsigned int lock_nb,
    const struct Timing* clear, const unsigned int clear_nb,
    const struct Label* labels, const unsigned int labels_nb,
    const struct DigitsPosition score_pos,
    const struct DigitsPosition level_pos,
    const struct DigitsPosition level_target_pos,
    uint32_t (*score_f)(
        uint32_t, uint32_t, uint32_t, uint32_t,
        uint32_t, uint32_t, uint32_t, uint32_t),
    void (*grade_f)(uint32_t, unsigned int, Grade *grade)) :
        score_func(score_f),
        grade_func(grade_f),
        m_name(name),
        m_sonic_drop(sonic_drop),
        m_display_score(display_score),
        m_section(section),
        m_keep_down(keep_down),
        m_old_locking_style(old_locking_style),
        m_credit_roll(credit_roll),
        m_width(width),
        m_height(height),
        m_max_level(max_level),
        m_initial_grade(initial_grade),
        m_random_tries(random_tries),
        m_gravity_nb(gravity_nb),
        m_are_nb(are_nb),
        m_line_are_nb(line_are_nb),
        m_das_nb(das_nb),
        m_lock_nb(lock_nb),
        m_clear_nb(clear_nb),
        m_labels_nb(labels_nb),
        m_gravity(gravity),
        m_are(are),
        m_line_are(line_are),
        m_das(das),
        m_lock(lock),
        m_clear(clear),
        m_labels(labels),
        m_score_pos(score_pos),
        m_level_pos(level_pos),
        m_level_target_pos(level_target_pos) {
    #ifdef DEBUG
    print("Mode constructor: %s\n", m_name);
    #endif
}

unsigned int Mode::are(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_are_nb; i++) {
        if (level >= m_are[i].level) {
            last = i;
        }

        if (level < m_are[i].level) {
            break;
        }
    }

    return m_are[last].value;
}

unsigned int Mode::line_are(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_line_are_nb; i++) {
        if (level >= m_line_are[i].level) {
            last = i;
        }

        if (level < m_line_are[i].level) {
            break;
        }
    }

    return m_line_are[last].value;
}

unsigned int Mode::das(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_das_nb; i++) {
        if (level >= m_das[i].level) {
            last = i;
        }

        if (level < m_das[i].level) {
            break;
        }
    }

    return m_das[last].value;
}

unsigned int Mode::lock(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_lock_nb; i++) {
        if (level >= m_lock[i].level) {
            last = i;
        }

        if (level < m_lock[i].level) {
            break;
        }
    }

    return m_lock[last].value;
}

unsigned int Mode::clear(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_clear_nb; i++) {
        if (level >= m_clear[i].level) {
            last = i;
        }

        if (level < m_clear[i].level) {
            break;
        }
    }

    return m_clear[last].value;
}

unsigned int Mode::gravity(unsigned int level) {
    unsigned int last = 0;

    for (unsigned int i = 0; i < m_gravity_nb; i++) {
        if (level >= m_gravity[i].level) {
            last = i;
        }

        if (level < m_gravity[i].level) {
            break;
        }
    }

    return m_gravity[last].value;
}

unsigned int Mode::section(unsigned int level) {
    if (m_section) {
        for (unsigned int i = 100; i < m_max_level; i += 100) {
            if (level < i) {
                return i;
            }
        }
    }

    return m_max_level;
}
