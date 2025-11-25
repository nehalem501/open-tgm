/* Labels.cpp */

#include <Debug.h>
#include <Labels.h>

Labels::Labels() : m_initialized(false), m_mode(NULL) {
    printd(DebugCategory::LABELS, "Labels screen constructor");
}

void Labels::layout(const Position &parent) {
    m_implementation.layout(parent);
}

void Labels::draw() const {
    // TODO
}
