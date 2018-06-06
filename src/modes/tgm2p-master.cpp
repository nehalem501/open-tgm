/* tgm2p-master.cpp */

#include <Mode.h>
#ifdef DEBUG
#include <Global.h>
#endif
#include "tgm2p-master.h"

uint32_t tgm2p_master_score(uint32_t level, uint32_t lines, uint32_t soft,
                            uint32_t sonic, uint32_t combo, uint32_t bravo,
                            uint32_t lvl_aft_clear, uint32_t speed) {
    #ifdef DEBUG
    print("level: %d\n"
          "lines: %d\n"
          "soft: %d\n"
          "sonic: %d\n"
          "combo: %d\n"
          "bravo: %d\n"
          "lvl_aft_clear: %d\n"
          "speed: %d\n", level, lines, soft, sonic,
                         combo, bravo, lvl_aft_clear, speed);
    #endif

    uint32_t tmp = (level + lines) / 4;
    if ((level + lines) % 4 != 0) // Round Up
        tmp++;
    uint32_t tmp2 = lvl_aft_clear / 2;
    if (lvl_aft_clear % 2 != 0) // Round Up
        tmp2++;
    return (tmp + soft + (2 * sonic)) * lines * combo * bravo + tmp2 + (speed * 7);
}

void tgm2p_master_grade(uint32_t score, unsigned int level, Grade *grade) {
}

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
    {500, 5120}
};

static struct Timing TGM2P_MASTER_ARE[3] = {
    {0, 25},
    {701, 16},
    {801, 12}
};

static struct Timing TGM2P_MASTER_LINE_ARE[4] = {
    {0, 25},
    {601, 16},
    {701, 12},
    {801, 6}
};

static struct Timing TGM2P_MASTER_DAS[3] = {
    {0, 14},
    {500, 8},
    {900, 6}
};

static struct Timing TGM2P_MASTER_LOCK[2] = {
    {0, 30},
    {901, 17}
};

static struct Timing TGM2P_MASTER_CLEAR[5] = {
    {0, 40},
    {500, 25},
    {601, 16},
    {701, 12},
    {801, 6}
};

static char TGM2P_MASTER_NEXT_STR[] = "NEXT";
static char TGM2P_MASTER_TIME_STR[] = "TIME";
static char TGM2P_MASTER_LEVEL_STR[] = "LEVEL";
static char TGM2P_MASTER_SCORE_STR[] = "SCORE";

static struct Label TGM2P_MASTER_LABELS[4] = {
    {TGM2P_MASTER_NEXT_STR, -1, 0},
    {TGM2P_MASTER_TIME_STR, 12, 20},
    {TGM2P_MASTER_LEVEL_STR, 12, 15},
    {TGM2P_MASTER_SCORE_STR, 12, 11}
};

struct Position TGM2P_MASTER_SCORE_POS = {12, 12};
struct Position TGM2P_MASTER_LVL_POS = {12, 16};
struct Position TGM2P_MASTER_LVL_TGT_POS = {12, 18};

Mode mode_tgm2p_master(
/*          name */ "TAP MASTER",
/*    sonic_drop */ true,
/* display_score */ true,
/*       section */ true,
/*     keep_down */ true,
/*   credit_roll */ CreditRoll::Required,
/*        size_x */ 10,
/*        size_y */ 22,
/*     max_level */ 999,
/* initial_grade */ Grade::_9,
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
/*      clear_nb */ 5,
/*        labels */ TGM2P_MASTER_LABELS,
/*     labels_nb */ 4,
/*     score_pos */ TGM2P_MASTER_SCORE_POS,
/*     level_pos */ TGM2P_MASTER_LVL_POS,
/*   lvl_tgt_pos */ TGM2P_MASTER_LVL_TGT_POS,
/*    score_func */ tgm2p_master_score,
/*    grade_func */ tgm2p_master_grade);
