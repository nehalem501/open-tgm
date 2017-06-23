/* modes.cpp */

#include <cstdlib>
#include <Mode.h>
#include "modes.h"

/* Include your mode's header here */
#include "tgm1.h"
#include "tgm2p-master.h"
#include "death.h"
#include "easy.h"

Mode* modes[NB_MODES] = {
    &mode_tgm1,
    &mode_tgm2p_master,
    &mode_easy,
    &mode_death
};


void initModes() {
}
