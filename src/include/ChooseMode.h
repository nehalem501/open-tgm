/* ChooseMode.h */

#ifndef CHOOSE_MODE_H
#define CHOOSE_MODE_H

#include <Position.h>
#include <Coordinates.h>
#include <Text.h>
#include <../modes/modes.h>

class ChooseMode {
    public:
        const static Coordinates m_coordinates;

        ChooseMode(const Position& parent);

        void draw() const;

        #ifdef RESIZABLE
        void resize(const Position& parent) {
            for (unsigned int i = 0; i < NB_MODES; i++) {
                m_modes_strings[i].resize(parent);
            }
        }
        #endif

        bool update(int *mode);

    private:
        bool m_selected;
        int m_mode;
        Text m_modes_strings[NB_MODES];
};

#endif // CHOOSE_MODE_H
