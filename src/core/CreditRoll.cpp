/* CreditRoll.cpp */

#include <stddef.h>
#include <TargetTypes.h>
#include <Debug.h>
#include <CreditRoll.h>

CreditRoll::CreditRoll() : m_mode(NULL), m_counter(0) {
    printd(DebugCategory::CREDIT_ROLL, "CreditRoll constructor");
}

void CreditRoll::draw() const {
    m_implementation.render();
}
