/* Mode.h */

#ifndef MODE_H
#define MODE_H

#include <TargetTypes.h>
#include <Position.h>
#include <Grade.h>
#include <CreditRoll.h>

struct Timing {
    unsigned int level;
    unsigned int value;
};

struct Label {
    char *string;
    int8_t x;
    int8_t y;
};

struct DigitsPosition {
    int8_t x;
    int8_t y;
};

class Mode {
    public:
        uint32_t (*score_func)(
            uint32_t, uint32_t, uint32_t, uint32_t,
            uint32_t, uint32_t, uint32_t, uint32_t);
        void (*grade_func)(uint32_t, unsigned int, Grade *grade);

        Mode(
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
            void (*grade_f)(uint32_t, unsigned int, Grade *grade));

        inline const char* name() { return m_name; };

        inline bool sonic_drop() { return m_sonic_drop; };
        inline bool display_score() { return m_display_score; };
        inline bool keep_down() { return m_keep_down; };
        inline bool old_locking_style() { return m_old_locking_style; };

        inline unsigned int credit_roll() { return m_credit_roll; };

        inline unsigned int width() { return m_width; };
        inline unsigned int height() { return m_height; };

        inline unsigned int max_level() { return m_max_level; };
        inline unsigned int random_tries() { return m_random_tries; };

        inline unsigned int labels_nb() { return m_labels_nb; };
        inline const Label* labels() { return m_labels; };
        inline Label get_label(unsigned int i) { return m_labels[i]; };

        inline Position score_position() {
            return Position(m_score_pos.x, m_score_pos.y);
        };
        inline Position level_position() {
            return Position(m_level_pos.x, m_level_pos.y);
        };
        inline Position level_target_position() {
            return Position(m_level_target_pos.x, m_level_target_pos.y);
        };

        unsigned int are(unsigned int level);
        unsigned int line_are(unsigned int level);
        unsigned int das(unsigned int level);
        unsigned int lock(unsigned int level);
        unsigned int clear(unsigned int level);
        unsigned int gravity(unsigned int level);
        unsigned int section(unsigned int level);

    private:
        const char* m_name;

        const bool m_sonic_drop;
        const bool m_display_score;
        const bool m_section;
        const bool m_keep_down;
        const bool m_old_locking_style;

        const unsigned int m_credit_roll;

        const unsigned int m_width, m_height;
        const unsigned int m_max_level;
        const unsigned int m_initial_grade;
        const unsigned int m_random_tries;

        const unsigned int m_gravity_nb;
        const unsigned int m_are_nb;
        const unsigned int m_line_are_nb;
        const unsigned int m_das_nb;
        const unsigned int m_lock_nb;
        const unsigned int m_clear_nb;
        const unsigned int m_labels_nb;

        const struct Timing* m_gravity;
        const struct Timing* m_are;
        const struct Timing* m_line_are;
        const struct Timing* m_das;
        const struct Timing* m_lock;
        const struct Timing* m_clear;
        const struct Label* m_labels;

        const struct DigitsPosition m_score_pos;
        const struct DigitsPosition m_level_pos;
        const struct DigitsPosition m_level_target_pos;
};

#endif
