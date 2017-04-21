/* tgm2p-master.cpp */

#include <Mode.h>
#include "tgm2p-master.h"

static struct Timing TGM2P_MASTER_GRAVITY[30] = {
    {0, 4},
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
    {500, 5120}};

static struct Timing TGM2P_MASTER_ARE[3] = {
    {0, 25},
    {701, 16},
    {801, 12}};

static struct Timing TGM2P_MASTER_LINE_ARE[4] = {
    {0, 25},
    {601, 16},
    {701, 12},
    {801, 6}};

static struct Timing TGM2P_MASTER_DAS[3] = {
    {0, 14},
    {500, 8},
    {900, 6}};

static struct Timing TGM2P_MASTER_LOCK[2] = {
    {0, 30},
    {901, 17}};

static struct Timing TGM2P_MASTER_CLEAR[5] = {
    {0, 40},
    {500, 25},
    {601, 16},
    {701, 12},
    {801, 6}};

Mode mode_tgm2p_master(
/*          name */ "TGM2P MASTER",
/*    sonic_drop */ true,
/* display_score */ true,
/*       section */ true,
/*        size_x */ 10,
/*        size_y */ 22,
/*     max_level */ 999,
/*       gravity */ TGM2P_MASTER_GRAVITY,
/*    gravity_nb */ 30,
/*           are */ TGM2P_MASTER_ARE,
/*        are_nb */ 3,
/*      line_are */ TGM2P_MASTER_LINE_ARE,
/*   line_are_nb */ 4,
/*           das */ TGM2P_MASTER_DAS,
/*        das_nb */ 3,
/*          lock */ TGM2P_MASTER_LOCK,
/*       lock_nb */ 2,
/*         clear */ TGM2P_MASTER_CLEAR,
/*      clear_nb */ 5);
