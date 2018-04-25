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
    GRADE_M,
    GRADE_GM,
    GRADE_MAX_NB
};

enum {
    MROLL_REQUIRED,
    MROLL_PLAYABLE,
    NO_MROLL
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
    private:
        const char* m_name;

        bool m_sonic_drop;
        bool m_display_score;
        bool m_section;
        //bool m_line_are_test;
        bool m_keep_down;

        unsigned int m_width, m_height;
        unsigned int m_max_level;

        unsigned int m_gravity_nb;
        unsigned int m_are_nb;
        unsigned int m_line_are_nb;
        unsigned int m_das_nb;
        unsigned int m_lock_nb;
        unsigned int m_clear_nb;
    public: // TODO sfml: LabelsImpl.cpp:23/44
        unsigned int m_labels_nb;

    private:
        struct Timing* m_gravity;
        struct Timing* m_are;
        struct Timing* m_line_are;
        struct Timing* m_das;
        struct Timing* m_lock;
        struct Timing* m_clear;

    public: // TODO sfml: LabelsImpl.cpp:23/44
        struct Label* m_labels;

    private:
        struct Position m_score_pos;
        struct Position m_level_pos;
        struct Position m_level_target_pos;

    public:
        uint32_t (*score_func)(uint32_t, uint32_t, uint32_t, uint32_t,
                               uint32_t, uint32_t, uint32_t, uint32_t);

        Mode(const char* name, bool sonic_drop, bool display_score,
             bool section, bool keep_down, unsigned int width,
             unsigned int height, unsigned int max_level,
             struct Timing* gravity, unsigned int gravity_nb,
             struct Timing* are, unsigned int are_nb,
             struct Timing* line_are, unsigned int line_are_nb,
             struct Timing* das, unsigned int das_nb,
             struct Timing* lock, unsigned int lock_nb,
             struct Timing* clear, unsigned int clear_nb,
             struct Label* labels, unsigned int labels_nb,
             struct Position score_pos, struct Position level_pos,
             struct Position level_target_pos,
             uint32_t (*func)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t,
                              uint32_t, uint32_t, uint32_t));

        inline const char* name() { return m_name; };

        inline bool sonic_drop() { return m_sonic_drop; };
        inline bool display_score() { return m_display_score; };
        inline bool keep_down() { return m_keep_down; };

        inline unsigned int width() { return m_width; };
        inline unsigned int height() { return m_height; };

        inline unsigned int max_level() { return m_max_level; };

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
