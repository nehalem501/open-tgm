/* Labels.h */

#ifndef LABELS_H
#define LABELS_H

#include <Position.h>
#include <Mode.h>
#include <LabelsImpl.h>

class Labels {
    public:
        Labels();

        void layout(const Position &parent);
        void draw() const;

        #ifdef RESIZABLE
        inline void resize() { m_implementation.resize(); }
        #endif

        inline void set_mode(Mode new_mode) {
            m_mode = new_mode;
            m_initialized = true;
        };

        inline bool initialized() { return m_initialized; };

    private:
        bool m_initialized;
        Mode m_mode;
        LabelsImpl m_implementation;
};

#endif // LABELS_H
