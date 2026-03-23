/* Block.h */

#ifndef BLOCK_H
#define BLOCK_H

#include <TargetTypes.h>

enum class Shape: uint8_t {
    Empty = 0,
    I = 0b001 << 1,
    Z = 0b010 << 1,
    S = 0b011 << 1,
    J = 0b100 << 1,
    L = 0b101 << 1,
    O = 0b110 << 1,
    T = 0b111 << 1,
    Mask = 0b111 << 1,
    NumberOf = 7,
};

struct Outline {
    enum: uint8_t {
        Left   = 0b0001 << 4,
        Right  = 0b0010 << 4,
        Top    = 0b0100 << 4,
        Bottom = 0b1000 << 4,
        Mask   = 0b1111 << 4,
    };
};

struct VisibleFrames {
    enum: uint16_t {
        Invisible = 3,
        Fading    = 300,
        Mask      = 0b1'1111'1111,
    };
};

class Block {
    public:
        const static Block Empty;

        inline constexpr Block() : m_value(0) { };

        inline void color(Shape color) { m_value = static_cast<uint8_t>(color) << 8; }

        inline void add_outline(uint8_t outline) { m_value |= outline << 8; }
        inline void reset_outline() { m_value &= ~(Outline::Mask << 8); }

        inline void inc_visible_frames() { m_value++; }
        inline void reset_visible_frames() { m_value &= ~VisibleFrames::Mask; }

        inline bool filled() { return static_cast<uint8_t>(m_value >> 8) & (Outline::Mask | static_cast<uint8_t>(Shape::Mask)); }
        inline bool empty() { return !filled(); }

        //inline bool blink();

        inline Shape color() { return static_cast<Shape>(static_cast<uint8_t>(m_value >> 8) & static_cast<uint8_t>(Shape::Mask)); }
        inline uint8_t outline() { return static_cast<uint8_t>(static_cast<uint8_t>(m_value >> 8) & Outline::Mask); }
        inline uint16_t visible_frames() { return m_value & VisibleFrames::Mask; }

        inline bool outline_left() { return outline() & Outline::Left; }
        inline bool outline_right() { return outline() & Outline::Right; }
        inline bool outline_top() { return outline() & Outline::Top; }
        inline bool outline_bottom() { return outline() & Outline::Bottom; }

    private:
        inline constexpr Block(uint16_t value) : m_value(value) { };

        uint16_t m_value;
};

#endif
