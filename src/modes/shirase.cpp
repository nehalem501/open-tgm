/* shirase.cpp */

#include <Mode.h>
#ifdef DEBUG
#include <Global.h>
#endif
#include "shirase.h"

uint32_t shirase_score(uint32_t level, uint32_t lines, uint32_t soft,
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

void shirase_grade(uint32_t, unsigned int level, Grade *grade) {
    if (level == 1300) {
        grade->m_grade = Grade::GM;
    } else if (level >= 500) {
        grade->m_grade = Grade::M;
    }
}

static struct Timing SHIRASE_GRAVITY[1] = {{0, 5120}};

static struct Timing SHIRASE_ARE[2] = {
    {0, 10},
    {300, 4}
};

static struct Timing SHIRASE_LINE_ARE[5] = {
    {0, 6},
    {100, 5},
    {200, 4},
    {500, 3},
    {1299, 4}
};

static struct Timing SHIRASE_DAS[3] = {
    {0, 8},
    {100, 6},
    {500, 4}
};

static struct Timing SHIRASE_LOCK[8] = {
    {0, 18},
    {200, 17},
    {300, 15},
    {500, 13},
    {600, 12},
    {1100, 10},
    {1200, 8},
    {1299, 15}
};

static struct Timing SHIRASE_CLEAR[5] = {
    {0, 6},
    {100, 5},
    {200, 4},
    {500, 3},
    {1299, 6}
};

static char SHIRASE_NEXT_STR[] = "NEXT";
static char SHIRASE_TIME_STR[] = "TIME";
static char SHIRASE_LEVEL_STR[] = "LEVEL";
//static char SHIRASE_POINTS_STR[] = "POINTS";

static struct Label SHIRASE_LABELS[3] = {
    {SHIRASE_NEXT_STR, -1, 0},
    {SHIRASE_TIME_STR, 12, 20},
    {SHIRASE_LEVEL_STR, 12, 15},
    //{SHIRASE_POINTS_STR, 12, 11}
};

struct Position SHIRASE_SCORE_POS = {12, 12};
struct Position SHIRASE_LEVEL_POS = {12, 16};
struct Position SHIRASE_LVL_TGT_POS = {12, 18};

Mode mode_shirase(
/*          name */ "SHIRASE",
/*    sonic_drop */ false,
/* display_score */ false,
/*       section */ true,
/*     keep_down */ false,
/* old_lck_style */ false,
/*   credit_roll */ CreditRoll::Playable,
/*        size_x */ 10,
/*        size_y */ 22,
/*     max_level */ 1300,
/* initial_grade */ Grade::None,
/*  random_tries */ 6,
/*       gravity */ SHIRASE_GRAVITY,
/*    gravity_nb */ 1,
/*           are */ SHIRASE_ARE,
/*        are_nb */ 2,
/*      line_are */ SHIRASE_LINE_ARE,
/*   line_are_nb */ 5,
/*           das */ SHIRASE_DAS,
/*        das_nb */ 3,
/*          lock */ SHIRASE_LOCK,
/*       lock_nb */ 8,
/*         clear */ SHIRASE_CLEAR,
/*      clear_nb */ 5,
/*        labels */ SHIRASE_LABELS,
/*     labels_nb */ 3,
/*     score_pos */ SHIRASE_SCORE_POS,
/*     level_pos */ SHIRASE_LEVEL_POS,
/*   lvl_tgt_pos */ SHIRASE_LVL_TGT_POS,
/*    score_func */ shirase_score,
/*    grade_func */ shirase_grade);
