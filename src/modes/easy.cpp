/* easy.cpp */

#include <Mode.h>
#ifdef DEBUG
#include <Global.h>
#endif
#include "easy.h"

uint32_t easy_score(uint32_t level, uint32_t lines, uint32_t soft,
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
    uint32_t score = (tmp + soft + (2 * sonic)) * lines * combo * bravo + tmp2 + (speed * 7);
    return 6 * score; // TODO Bonus end of game
}

void easy_grade(uint32_t, unsigned int, Grade*) {
}

static struct Timing EASY_GRAVITY[32] = {
    {0, 4},
    {8, 5},
    {19, 6},
    {35, 8},
    {40, 10},
    {50, 12},
    {60, 16},
    {70, 32},
    {80, 48},
    {90, 64},
    {100, 4},
    {108, 5},
    {119, 6},
    {125, 8},
    {131, 12},
    {139, 32},
    {149, 48},
    {156, 80},
    {164, 112},
    {174, 128},
    {180, 144},
    {200, 16},
    {212, 48},
    {221, 80},
    {232, 112},
    {244, 144},
    {256, 176},
    {267, 192},
    {277, 208},
    {287, 224},
    {295, 240},
    {300, 5120}
};

static struct Timing EASY_ARE[1] = {{0, 25}};

static struct Timing EASY_LINE_ARE[1] = {{0, 25}};

static struct Timing EASY_DAS[1] = {{0, 14}};

static struct Timing EASY_LOCK[1] = {{0, 30}};

static struct Timing EASY_CLEAR[1] = {{0, 40}};

static char EASY_NEXT_STR[] = "NEXT";
static char EASY_TIME_STR[] = "TIME";
static char EASY_LEVEL_STR[] = "LEVEL";
static char EASY_POINTS_STR[] = "POINTS";

static struct Label EASY_LABELS[4] = {
    {EASY_NEXT_STR, -1, 0},
    {EASY_TIME_STR, 12, 20},
    {EASY_LEVEL_STR, 12, 15},
    {EASY_POINTS_STR, 12, 11}
};

struct DigitsPosition EASY_SCORE_POS = {12, 12};
struct DigitsPosition EASY_LEVEL_POS = {12, 16};
struct DigitsPosition EASY_LVL_TGT_POS = {12, 18};

Mode mode_easy(
/*          name */ "EASY",
/*    sonic_drop */ true,
/* display_score */ true,
/*       section */ true,
/*     keep_down */ true,
/* old_lck_style */ false,
/*   credit_roll */ CreditRoll::Playable,
/*        size_x */ 10,
/*        size_y */ 22,
/*     max_level */ 300,
/* initial_grade */ Grade::None,
/*  random_tries */ 6,
/*       gravity */ EASY_GRAVITY,
/*    gravity_nb */ 32,
/*           are */ EASY_ARE,
/*        are_nb */ 1,
/*      line_are */ EASY_LINE_ARE,
/*   line_are_nb */ 1,
/*           das */ EASY_DAS,
/*        das_nb */ 1,
/*          lock */ EASY_LOCK,
/*       lock_nb */ 1,
/*         clear */ EASY_CLEAR,
/*      clear_nb */ 1,
/*        labels */ EASY_LABELS,
/*     labels_nb */ 4,
/*     score_pos */ EASY_SCORE_POS,
/*     level_pos */ EASY_LEVEL_POS,
/*   lvl_tgt_pos */ EASY_LVL_TGT_POS,
/*    score_func */ easy_score,
/*    grade_func */ easy_grade);
