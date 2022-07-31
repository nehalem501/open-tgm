/* tgm1.cpp */

#ifdef DEBUG
#include <TargetTypes.h>
#endif

#include <RawMode.h>
#include <Frame.h>
#include <Debug.h>
#include "tgm1.h"

uint32_t tgm1_score(uint32_t level, uint32_t lines, uint32_t soft, uint32_t,
                    uint32_t combo, uint32_t bravo, uint32_t, uint32_t) {
    uint32_t tmp = (level + lines) / 4;
    if ((level + lines) % 4 != 0)
        tmp++;
    return (tmp + soft) * lines * combo * bravo;
}

struct Condition {
    unsigned int grade;
    uint32_t score;
};

static const struct Condition TGM1_GRADE_CONDITIONS[19] = {
    {Grade::_9, 0},
    {Grade::_8, 400},
    {Grade::_7, 800},
    {Grade::_6, 1400},
    {Grade::_5, 2000},
    {Grade::_4, 3500},
    {Grade::_3, 5500},
    {Grade::_2, 8000},
    {Grade::_1, 12000},
    {Grade::S1, 16000},
    {Grade::S2, 22000},
    {Grade::S3, 30000},
    {Grade::S4, 40000},
    {Grade::S5, 52000},
    {Grade::S6, 66000},
    {Grade::S7, 82000},
    {Grade::S8, 100000},
    {Grade::S9, 120000},
    {Grade::GM, 126000}
};

void tgm1_grade(uint32_t score, unsigned int, Grade *grade) {
    printd(DebugCategory::SCORE, "Previous GRADE: ", grade->get_string());

    for (unsigned int i = grade->get(); i < 18; i++) {
        if (score >= TGM1_GRADE_CONDITIONS[i].score) {
            grade->set(TGM1_GRADE_CONDITIONS[i].grade);
        }
    }

    printd(DebugCategory::SCORE, "GRADE: ", grade->get_string());
}

static const struct Timing TGM1_GRAVITY[30] = {
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

static const struct Timing TGM1_ARE[1] = {{0, 30}};

static const struct Timing TGM1_LINE_ARE[1] = {{0, 30}};

static const struct Timing TGM1_DAS[1] = {{0, 14}};

static const struct Timing TGM1_LOCK[1] = {{0, 30}};

static const struct Timing TGM1_CLEAR[1] = {{0, 41}};

static const char TGM1_NEXT_STR[] = "NEXT";
static const char TGM1_TIME_STR[] = "TIME";
static const char TGM1_LEVEL_STR[] = "LEVEL";
static const char TGM1_POINTS_STR[] = "POINTS";
static const char TGM1_GRADE_STR[] = "GRADE";
static const char TGM1_NEXT_AT_STR[] = "NEXT AT";

static const struct Label TGM1_LABELS[6] = {
    {TGM1_NEXT_STR, -1, 0},
    {TGM1_TIME_STR, 12, 20},
    {TGM1_LEVEL_STR, 12, 15},
    {TGM1_POINTS_STR, 12, 11},
    {TGM1_GRADE_STR, 12, 1},
    {TGM1_NEXT_AT_STR, 12, 6}
};

static const struct DigitsPosition TGM1_SCORE_POS = {12, 12};
static const struct DigitsPosition TGM1_LEVEL_POS = {12, 16};
static const struct DigitsPosition TGM1_LVL_TGT_POS = {12, 18};

const RawMode mode_tgm1 = {
/*          name */ "TGM",
/*    sonic_drop */ false,
/* display_score */ true,
/*       section */ true,
/*     keep_down */ true,
/* old_lck_style */ true,
/*   frame_color */ FrameColors::NORMAL,
/*   credit_roll */ CreditRoll::Playable,
/*   stack_width */ 10,
/*  stack_height */ 22,
/*     max_level */ 999,
/* initial_grade */ Grade::_9,
/*  random_tries */ 4,
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
/*   lvl_tgt_pos */ TGM1_LVL_TGT_POS,
/*    score_func */ tgm1_score,
/*    grade_func */ tgm1_grade
};
