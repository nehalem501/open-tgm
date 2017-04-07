/* modes.h */

#ifndef MODES_H
#define MODES_H

#include "../common/mode.h"

namespace Modes {
    enum {
        TGM = 0,
        TAP_MASTER,
        DEATH,
        MODES_MAX
    };
}

void initModes();

#endif
