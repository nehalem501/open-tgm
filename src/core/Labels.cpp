/* Labels.cpp */

#include <Debug.h>
#include <Labels.h>

Labels::Labels() : m_initialized(false), m_mode(NULL) {
    printd(DebugCategory::LABELS, "Labels screen constructor");
    for (unsigned int i = 0; i < MAX_LABELS; i++) {
        m_labels_strings[i].font(Font::Label);
    }
}

void Labels::layout(const Position &parent) {
    m_implementation.layout(parent);
    update_labels(parent); // TODO: no need to update text here
}

void Labels::set_mode(Mode new_mode, const Position &parent) {
    m_mode = new_mode;
    m_initialized = true;
    update_labels(parent);
};

void Labels::update_labels(const Position &parent) {
    if (!m_initialized) {
        return;
    }

    unsigned int labels_nb = m_mode.labels_nb();
    unsigned int i;
    for (i = 0; i < labels_nb; i++) {
        const Label& label = m_mode.get_label(i);
        m_labels_strings[i].position(Coordinates(label.x, label.y), parent);
        m_labels_strings[i].text(label.string);
    }
    unsigned int remaining = MAX_LABELS - i;
    for (; i < remaining; i++) {
        m_labels_strings[i].text(NULL);
    }
}

void Labels::draw() const {
    for (unsigned int i = 0; i < MAX_LABELS; i++) {
        m_labels_strings[i].draw();
    }
}
