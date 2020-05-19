/* m_mode->h */

#ifndef MODE_H
#define MODE_H

#include <TargetTypes.h>
#include <Position.h>
#include <RawMode.h>
#include <Grade.h>
#include <CreditRoll.h>

class Mode {
    public:
        Mode(const RawMode *raw_mode);

        inline const char* name() { return m_mode->name; };

        inline bool sonic_drop() { return m_mode->sonic_drop; };
        inline bool display_score() { return m_mode->display_score; };
        inline bool keep_down() { return m_mode->keep_down; };
        inline bool old_locking_style() { return m_mode->old_locking_style; };

        inline unsigned int credit_roll() { return m_mode->credit_roll; };

        inline unsigned int width() const { return m_mode->width; };
        inline unsigned int height() const { return m_mode->height; };

        inline unsigned int max_level() { return m_mode->max_level; };
        inline unsigned int initial_grade() { return m_mode->initial_grade; };
        inline unsigned int random_tries() { return m_mode->randotries; };

        inline unsigned int labels_nb() { return m_mode->labels_nb; };
        inline const Label* labels() { return m_mode->labels; };
        inline Label get_label(unsigned int i) { return m_mode->labels[i]; };

        inline Position score_position() {
            return Position(m_mode->score_pos.x, m_mode->score_pos.y);
        };
        inline Position level_position() {
            return Position(m_mode->level_pos.x, m_mode->level_pos.y);
        };
        inline Position level_target_position() {
            return Position(
                m_mode->level_target_pos.x,
                m_mode->level_target_pos.y);
        };

        unsigned int are(unsigned int level);
        unsigned int line_are(unsigned int level);
        unsigned int das(unsigned int level);
        unsigned int lock(unsigned int level);
        unsigned int clear(unsigned int level);
        unsigned int gravity(unsigned int level);
        unsigned int section(unsigned int level);

        inline uint32_t score(
            uint32_t level,
            uint32_t lines,
            uint32_t soft,
            uint32_t sonic,
            uint32_t combo,
            uint32_t bravo,
            uint32_t lvl_aft_clear,
            uint32_t speed) {
            return m_mode->score_func(
                level,
                lines,
                soft,
                sonic,
                combo,
                bravo,
                lvl_aft_clear,
                speed);
        }

        inline void grade(uint32_t score, unsigned int level, Grade* grade) {
            m_mode->grade_func(score, level, grade);
        }

    private:
        const RawMode *m_mode;
};

#endif
