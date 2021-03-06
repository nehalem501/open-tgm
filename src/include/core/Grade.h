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

            #ifdef DEBUG
            const char* get_string() {
                switch (m_grade) {
                    case Grade::None:
                        return "None";

                    case Grade::_9:
                        return "9";

                    case Grade::_8:
                        return "8";

                    case Grade::_7:
                        return "7";

                    case Grade::_6:
                        return "6";

                    case Grade::_5:
                        return "5";

                    case Grade::_4:
                        return "4";

                    case Grade::_3:
                        return "3";

                    case Grade::_2:
                        return "2";

                    case Grade::_1:
                        return "1";

                    case Grade::S1:
                        return "S1";

                    case Grade::S2:
                        return "S2";

                    case Grade::S3:
                        return "S3";

                    case Grade::S4:
                        return "S4";

                    case Grade::S5:
                        return "S5";

                    case Grade::S6:
                        return "S6";

                    case Grade::S7:
                        return "S7";

                    case Grade::S8:
                        return "S8";

                    case Grade::S9:
                        return "S9";

                    case Grade::M:
                        return "M";

                    case Grade::GM:
                        return "GM";

                    default:
                        break;
                }

                return "Not valid";
            }
            #endif

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

#endif // CORE_GRADE_H
