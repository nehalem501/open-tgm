/* Background.cpp */

#include <TargetTypes.h>
#include <Background.h>

Background::Background() : m_options(false) {
    #ifdef DEBUG
    print("Background constructor\n");
    #endif
}

void Background::draw() const {
    m_implementation.render(m_options);
}
