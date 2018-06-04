/* Grade.h */

#ifndef CORE_GRADE_H
#define CORE_GRADE_H

#include <TargetTypes.h>

namespace Core {
    class Grade {
        public:
            Grade();
            inline void set(unsigned int value) {
                m_has_changed = true;
                m_grade = value;
            }

            bool m_has_changed;
            unsigned int m_internal;
            unsigned int m_points;
            unsigned int m_grade;
            unsigned int m_counter;

            enum {
                None = 0,
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
}

#endif
