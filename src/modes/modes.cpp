/* modes.cpp */

#include <cstdlib>
#include <Mode.h>
#include "modes.h"

/* Include your mode's header here */
#include "tgm1.h"
#include "tgm2p-master.h"

Mode* modes[NB_MODES] = {
    &mode_tgm1,
    &mode_tgm2p_master,
    &mode_tgm2p_master,

    &mode_tgm2p_master,
    &mode_tgm2p_master,
    &mode_tgm2p_master
};


void initModes() {
}
