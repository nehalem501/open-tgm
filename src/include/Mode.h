/* Mode.h */

#ifndef MODE_H
#define MODE_H

#include <Grade.h>
#include <CreditRoll.h>
#include <TargetTypes.h>

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
    private:
        const char* m_name;

        bool m_sonic_drop;
        bool m_display_score;
        bool m_section;
        //bool m_line_are_test;
        bool m_keep_down;

        unsigned int m_credit_roll;

        unsigned int m_width, m_height;
        unsigned int m_max_level;
        unsigned int m_initial_grade;

        unsigned int m_gravity_nb;
        unsigned int m_are_nb;
        unsigned int m_line_are_nb;
        unsigned int m_das_nb;
        unsigned int m_lock_nb;
        unsigned int m_clear_nb;
        unsigned int m_labels_nb;

        struct Timing* m_gravity;
        struct Timing* m_are;
        struct Timing* m_line_are;
        struct Timing* m_das;
        struct Timing* m_lock;
        struct Timing* m_clear;
        struct Label* m_labels;

    private:
        struct Position m_score_pos;
        struct Position m_level_pos;
        struct Position m_level_target_pos;

    public:
        uint32_t (*score_func)(uint32_t, uint32_t, uint32_t, uint32_t,
                               uint32_t, uint32_t, uint32_t, uint32_t);
        void (*grade_func)(uint32_t, unsigned int, Grade *grade);

        Mode(const char* name,
             bool sonic_drop,
             bool display_score,
             bool section,
             bool keep_down,
             unsigned int credit_roll,
             unsigned int width,
             unsigned int height,
             unsigned int max_level,
             unsigned int initial_grade,
             struct Timing* gravity, unsigned int gravity_nb,
             struct Timing* are, unsigned int are_nb,
             struct Timing* line_are, unsigned int line_are_nb,
             struct Timing* das, unsigned int das_nb,
             struct Timing* lock, unsigned int lock_nb,
             struct Timing* clear, unsigned int clear_nb,
             struct Label* labels, unsigned int labels_nb,
             struct Position score_pos,
             struct Position level_pos,
             struct Position level_target_pos,
             uint32_t (*score_f)(uint32_t, uint32_t, uint32_t, uint32_t,
                                 uint32_t, uint32_t, uint32_t, uint32_t),
             void (*grade_f)(uint32_t, unsigned int, Grade *grade));

        inline const char* name() { return m_name; };

        inline bool sonic_drop() { return m_sonic_drop; };
        inline bool display_score() { return m_display_score; };
        inline bool keep_down() { return m_keep_down; };

        inline unsigned int credit_roll() { return m_credit_roll; };

        inline unsigned int width() { return m_width; };
        inline unsigned int height() { return m_height; };

        inline unsigned int max_level() { return m_max_level; };

        inline unsigned int labels_nb() { return m_labels_nb; };
        inline const Label* labels() { return m_labels; };
        inline Label get_label(unsigned int i) { return m_labels[i]; };

        inline int8_t score_pos_x() { return m_score_pos.x; };
        inline int8_t score_pos_y() { return m_score_pos.y; };

        inline int8_t level_pos_x() { return m_level_pos.x; };
        inline int8_t level_pos_y() { return m_level_pos.y; };

        inline int8_t level_target_pos_x() { return m_level_target_pos.x; };
        inline int8_t level_target_pos_y() { return m_level_target_pos.y; };

        unsigned int are(unsigned int level);
        unsigned int line_are(unsigned int level);
        unsigned int das(unsigned int level);
        unsigned int lock(unsigned int level);
        unsigned int clear(unsigned int level);
        unsigned int gravity(unsigned int level);
        unsigned int section(unsigned int level);
};

#endif
