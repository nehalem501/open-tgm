/* Grade.cpp */

#include <Grade.h>

Grade::Grade() :
        m_grade(Grade::None),
        m_internal(0),
        m_points(0),
        m_counter(0) {
}

void Grade::update() {
    // TODO
    m_internal++;
    m_points++;
    m_counter++;
}

void Grade::draw() const {
    m_implementation.render();
}
