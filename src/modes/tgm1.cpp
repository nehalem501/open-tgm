/* tgm1.cpp */

#include <stdint.h>
#include <Mode.h>
#include "tgm1.h"

uint32_t tgm1_score(uint32_t level, uint32_t lines, uint32_t soft,
                    uint32_t sonic, uint32_t combo, uint32_t bravo,
                    uint32_t lvl_aft_clear, uint32_t speed) {
    uint32_t tmp = (level + lines) / 4;
    if ((level + lines) % 4 != 0)
        tmp++;
    return (tmp + soft) * lines * combo * bravo;
}

static struct Timing TGM1_GRAVITY[30] = {
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

static struct Timing TGM1_ARE[1] = {{0, 30}};

static struct Timing TGM1_LINE_ARE[1] = {{0, 30}};

static struct Timing TGM1_DAS[1] = {{0, 14}};

static struct Timing TGM1_LOCK[1] = {{0, 30}};

static struct Timing TGM1_CLEAR[1] = {{0, 41}};

static char TGM1_NEXT_STR[] = "NEXT";
static char TGM1_TIME_STR[] = "TIME";
static char TGM1_LEVEL_STR[] = "LEVEL";
static char TGM1_POINTS_STR[] = "POINTS";
static char TGM1_GRADE_STR[] = "GRADE";
static char TGM1_NEXT_AT_STR[] = "NEXT AT";

static struct Label TGM1_LABELS[6] = {
    {TGM1_NEXT_STR, -2, 0},
    {TGM1_TIME_STR, 12, 20},
    {TGM1_LEVEL_STR, 12, 15},
    {TGM1_POINTS_STR, 12, 11},
    {TGM1_GRADE_STR, 12, 1},
    {TGM1_NEXT_AT_STR, 12, 6}
};

struct Position TGM1_SCORE_POS = {12, 12};
struct Position TGM1_LEVEL_POS = {12, 16};
struct Position TGM1_LVL_TGT_POS = {12, 18};

Mode mode_tgm1(
/*          name */ "TGM",
/*    sonic_drop */ true, //TODO
/* display_score */ true,
/*       section */ true,
/*        size_x */ 10,
/*        size_y */ 22,
/*     max_level */ 999,
/*       gravity */ TGM1_GRAVITY,
/*    gravity_nb */ 30,
/*           are */ TGM1_ARE,
/*        are_nb */ 1,
/*      line_are */ TGM1_LINE_ARE,
/*   line_are_nb */ 1,
/*           das */ TGM1_DAS,
/*        das_nb */ 1,
/*          lock */ TGM1_LOCK,
/*       lock_nb */ 1,
/*         clear */ TGM1_CLEAR,
/*      clear_nb */ 1,
/*        labels */ TGM1_LABELS,
/*     labels_nb */ 6,
/*     score_pos */ TGM1_SCORE_POS,
/*     level_pos */ TGM1_LEVEL_POS,
/*   lvl_tgt_pos */ TGM1_LVL_TGT_POS);
