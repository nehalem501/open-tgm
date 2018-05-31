/* Grade.h */

#ifndef CORE_GRADE_H
#define CORE_GRADE_H

namespace Grade {
    enum {
        NONE = 0,
        _9,
        _8,
        _7,
        _6,
        _5,
        _4,
        _3,
        _2,
        _1,
        S1,
        S2,
        S3,
        S4,
        S5,
        S6,
        S7,
        S8,
        S9,
        M,
        GM,
        MAX_NB
    };
};

namespace Core {
    class Grade {
        public:
            Grade();
            inline void set(unsigned int value) {
                m_grade = value;
                m_has_changed = true;
            }

        protected:
            bool m_has_changed;
            unsigned int m_grade;
    };
}

#endif
