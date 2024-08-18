/* Shapes.h */

#ifndef SHAPES_H
#define SHAPES_H

#include <TargetTypes.h>

#define NB_ROTATIONS 4
#define PIECE_SIZE 4

namespace Shape {
    enum : tiles_t {
        I = 0,
        Z,
        S,
        J,
        L,
        O,
        T,
        NB_SHAPES
    };
}

namespace Block {
    enum : tiles_t {
        GARBAGE = 7,
        HARD_BLOCK = 27,
        BLINK = 31,
        PIECE_BITS = 0x07u,
        ITEM_BITS = 0xF8u,
        BLINK_BIT = 0x8000u,
        HARD_BLOCK_BIT = 0x4000u
    };
}

namespace Item {
    enum : tiles_t {
        UP_DEL_FIELD = 0,
        DOWN_DEL_FIELD,
        LEFT_MOV_FIELD,
        RIGHT_MOV_FIELD,
        DEL_EVEN,
        DARK_BLOCK,
        MIRROR_BLOCK,
        X_RAY,
        R180_FIELD,
        DEATH_BLOCK,
        NEGA_FIELD,
        COLOR_BLOCK,
        SHOT_GUN,
        HARD_BLOCK,
        LASER,
        ROLL_ROLL,
        TRANSFORM,
        EXCHANGE_FIELD,
        FREE_FALL,
        NB_ITEMS
    };
}

enum struct ItemKind {
    NEUTRAL = 0,
    ATTACK,
    DEFENSE,
    NB_KINDS
};

enum {
    TOP = 12,
    BOTTOM,
    LEFT,
    RIGHT
};

extern const tiles_t PIECES[Shape::NB_SHAPES][NB_ROTATIONS][PIECE_SIZE * PIECE_SIZE];

#endif // SHAPES_H
