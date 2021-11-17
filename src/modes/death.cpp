/* death.cpp */

#ifdef DEBUG
#include <Global.h>
#endif

#include <RawMode.h>
#include <Frame.h>
#include <Debug.h>
#include "death.h"

uint32_t death_score(uint32_t level, uint32_t lines, uint32_t soft,
                     uint32_t sonic, uint32_t combo, uint32_t bravo,
                     uint32_t lvl_aft_clear, uint32_t speed) {
    printd("level: " << level);
    printd("lines: " << lines);
    printd("soft: " << soft);
    printd("sonic: " << sonic);
    printd("combo: " << combo);
    printd("bravo: " << bravo);
    printd("lvl_aft_clear: " << lvl_aft_clear);
    printd("speed: " << speed);

    uint32_t tmp = (level + lines) / 4;
    if ((level + lines) % 4 != 0) // Round Up
        tmp++;
    uint32_t tmp2 = lvl_aft_clear / 2;
    if (lvl_aft_clear % 2 != 0) // Round Up
        tmp2++;
    return (tmp + soft + (2 * sonic)) * lines * combo * bravo + tmp2 + (speed * 7);
}

void death_grade(uint32_t, unsigned int level, Grade *grade) {
    if (level == 999) {
        grade->set(Grade::GM);
    } else if (level >= 500) {
        grade->set(Grade::M);
    }
}

static const struct Timing DEATH_GRAVITY[1] = {{0, 5120}};

static const struct Timing DEATH_ARE[5] = {
    {0, 16},
    {101, 12},
    {301, 6},
    {401, 5},
    {500, 4}
};

static const struct Timing DEATH_LINE_ARE[4] = {
    {0, 12},
    {101, 6},
    {401, 5},
    {500, 4}
};

static const struct Timing DEATH_DAS[4] = {
    {0, 10},
    {200, 9},
    {300, 8},
    {400, 6}
};

static const struct Timing DEATH_LOCK[5] = {
    {0, 30},
    {101, 26},
    {201, 22},
    {301, 18},
    {401, 15}
};

static const struct Timing DEATH_CLEAR[4] = {
    {0, 12},
    {101, 6},
    {401, 5},
    {500, 4}
};

static const char DEATH_NEXT_STR[] = "NEXT";
static const char DEATH_TIME_STR[] = "TIME";
static const char DEATH_LEVEL_STR[] = "LEVEL";
static const char DEATH_POINTS_STR[] = "POINTS";

static const struct Label DEATH_LABELS[4] = {
    {DEATH_NEXT_STR, -1, 0},
    {DEATH_TIME_STR, 12, 20},
    {DEATH_LEVEL_STR, 12, 15},
    {DEATH_POINTS_STR, 12, 11}
};

static const struct DigitsPosition DEATH_SCORE_POS = {12, 12};
static const struct DigitsPosition DEATH_LEVEL_POS = {12, 16};
static const struct DigitsPosition DEATH_LVL_TGT_POS = {12, 18};

const RawMode mode_death = {
/*          name */ "DEATH",
/*    sonic_drop */ false,
/* display_score */ true,
/*       section */ true,
/*     keep_down */ false,
/* old_lck_style */ false,
/*   frame_color */ FrameColors::RED,
/*   credit_roll */ CreditRoll::Playable,
/*   stack_width */ 10,
/*  stack_height */ 22,
/*     max_level */ 999,
/* initial_grade */ Grade::None,
/*  random_tries */ 6,
/*       gravity */ DEATH_GRAVITY,
/*    gravity_nb */ 1,
/*           are */ DEATH_ARE,
/*        are_nb */ 5,
/*      line_are */ DEATH_LINE_ARE,
/*   line_are_nb */ 4,
/*           das */ DEATH_DAS,
/*        das_nb */ 4,
/*          lock */ DEATH_LOCK,
/*       lock_nb */ 5,
/*         clear */ DEATH_CLEAR,
/*      clear_nb */ 4,
/*        labels */ DEATH_LABELS,
/*     labels_nb */ 4,
/*     score_pos */ DEATH_SCORE_POS,
/*     level_pos */ DEATH_LEVEL_POS,
/*   lvl_tgt_pos */ DEATH_LVL_TGT_POS,
/*    score_func */ death_score,
/*    grade_func */ death_grade
};
