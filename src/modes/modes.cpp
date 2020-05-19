/* modes.cpp */

#include <stdlib.h>
#include <RawMode.h>
#include "modes.h"

/* Include your mode's header here */
#include "tgm1.h"
#include "tgm2p-master.h"
#include "death.h"
#include "easy.h"
#include "shirase.h"

const RawMode* raw_modes[NB_MODES] = {
    &mode_easy,
    &mode_tgm1,
    &mode_tgm2p_master,
    &mode_death,
    &mode_shirase
};
