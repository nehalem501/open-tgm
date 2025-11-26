/* Labels.h */

#ifndef LABELS_H
#define LABELS_H

#include <Position.h>
#include <Text.h>
#include <Mode.h>
#include <LabelsImpl.h>

#define MAX_LABELS 8

class Labels {
    public:
        Labels();

        void layout(const Position &parent);
        void draw() const;

        void set_mode(Mode new_mode, const Position &parent);

        #ifdef RESIZABLE
        inline void resize(const Position& parent) {
            for (unsigned int i = 0; i < MAX_LABELS; i++) {
                m_labels_strings[i].resize(parent);
            }
        }
        #endif

        inline bool initialized() { return m_initialized; };

    private:
        void update_labels(const Position &parent);

        bool m_initialized;
        Mode m_mode;
        Text m_labels_strings[MAX_LABELS];
        LabelsImpl m_implementation;
};

#endif // LABELS_H
