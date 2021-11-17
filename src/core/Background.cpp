/* Background.cpp */

#include <TargetTypes.h>
#include <Debug.h>
#include <Background.h>

Background::Background() : m_options(false) {
    printd("Background constructor");
}

void Background::draw() const {
    m_implementation.render(m_options);
}
