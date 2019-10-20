/* CreditRoll.cpp */

#include <stddef.h>
#include <TargetTypes.h>
#include <CreditRoll.h>

CreditRoll::CreditRoll() : m_mode(NULL), m_counter(0) {
    #ifdef DEBUG
    print("CreditRoll constructor\n");
    #endif
}

void CreditRoll::draw() const {
    m_implementation.render();
}
