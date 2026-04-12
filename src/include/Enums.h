/* Enums.h */

#ifndef ENUMS_H
#define ENUMS_H

#include <TargetTypes.h>

enum class Shape : uint8_t {
    Empty = 0,
    I = 0b001 << 1,
    Z = 0b010 << 1,
    S = 0b011 << 1,
    J = 0b100 << 1,
    L = 0b101 << 1,
    O = 0b110 << 1,
    T = 0b111 << 1,
};

struct Shapes {
    const static uint8_t Mask = 0b111 << 1;
    const static size_t Size = 4;
    const static size_t SmallSize = 3; // Size for other pieces than I
    const static size_t Rotations = 4;
    const static size_t NumberOf = 7;
};

struct Outline {
    enum : uint8_t {
        Left   = 0b0001 << 4,
        Right  = 0b0010 << 4,
        Top    = 0b0100 << 4,
        Bottom = 0b1000 << 4,
        Mask   = 0b1111 << 4,
    };
};

struct VisibleFrames {
    enum : uint16_t {
        Invisible = 3,
        Fading    = 300,
        Mask      = 0b1'1111'1111,
    };
};

enum class Rotation {
    None,
    Left,
    Right,
};

struct Items {
    enum class Type: uint8_t {
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

    enum struct Kind {
        NEUTRAL = 0,
        ATTACK,
        DEFENSE,
        NB_KINDS
    };

    const static size_t NumberOf = static_cast<size_t>(Type::NB_ITEMS);
};

enum class SceneState {
    HOME,
    GAME,
    SETTINGS
};

#endif // ENUMS_H
