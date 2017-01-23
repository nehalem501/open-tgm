/* modes.cpp */

#include "mode.h"
#include "modes.h"

Mode modes[Modes::MODES_MAX];

static struct Timing TGM_GRAVITY[30] = {{0, 4},
                                       {30, 6},
                                       {35, 8},
                                       {40, 10},
                                       {50, 12},
                                       
                                       {60, 16},
                                       {70, 32},
                                       {80, 48},
                                       {90, 64},
                                       {100, 80},
                                       
                                       {120, 96},
                                       {140, 112},
                                       {160, 128},
                                       {170, 144},
                                       {200, 4},
                                       
                                       {220, 32},
                                       {230, 64},
                                       {233, 96},
                                       {236, 128},
                                       {239, 160},
                                       
                                       {243, 192},
                                       {247, 224},
                                       {251, 256},
                                       {300, 512},
                                       {330, 768},
                                       
                                       {360, 1024},
                                       {400, 1280},
                                       {420, 1024},
                                       {450, 768},
                                       {500, 5120},
                                      };

static struct Timing TGM_ARE[1] = {{0, 30}};

static struct Timing TGM_LINE_ARE[1] = {{0, 30}};

static struct Timing TGM_DAS[1] = {{0, 14}};

static struct Timing TGM_LOCK[1] = {{0, 30}};

static struct Timing TGM_CLEAR[1] = {{0, 41}};

void initModes() {
    modes[Modes::TGM].name = "TGM";
    
    modes[Modes::TGM].sonic_drop = true; //TODO
    modes[Modes::TGM].display_score = true;
    
    modes[Modes::TGM].section = true;
    
    modes[Modes::TGM].size_x = 10;
    modes[Modes::TGM].size_y = 22;
    
    modes[Modes::TGM].max_level = 999;
    
    modes[Modes::TGM].gravity = TGM_GRAVITY;
    modes[Modes::TGM].gravity_nb = 30;

    modes[Modes::TGM].are = TGM_ARE;
    modes[Modes::TGM].are_nb = 1;
    
    modes[Modes::TGM].line_are = TGM_LINE_ARE;
    modes[Modes::TGM].line_are_nb = 1;
    
    modes[Modes::TGM].das = TGM_DAS;
    modes[Modes::TGM].das_nb = 1;
    
    modes[Modes::TGM].lock = TGM_LOCK;
    modes[Modes::TGM].lock_nb = 1;
    
    modes[Modes::TGM].clear = TGM_CLEAR;
    modes[Modes::TGM].clear_nb = 1;
}
