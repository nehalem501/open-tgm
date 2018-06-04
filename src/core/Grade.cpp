/* Grade.cpp */

#include <core/Grade.h>

Core::Grade::Grade() : m_has_changed(false),
                       m_internal(0),
                       m_points(0),
                       m_grade(Grade::None),
                       m_counter(0) {
}
