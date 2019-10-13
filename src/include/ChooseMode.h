/* ChooseMode.h */

#ifndef CHOOSE_MODE_H
#define CHOOSE_MODE_H

#include <Text.h>
#include <../modes/modes.h>


class ChooseMode {
    public:
        ChooseMode();

        void draw();
        
        void init();
        void update(int *state, int *mode);

    private:
        int m_mode;
        bool m_selected;
        Text m_modes_strings[NB_MODES];
};

#endif // CHOOSE_MODE_H
