/* Block.h */

#ifndef BLOCK_H
#define BLOCK_H

#include <TargetTypes.h>
#include <Enums.h>

/*namespace Block {

}*/

class Block {
    public:
        //const static Block Empty;

        enum : uint8_t {
            Blink = 0b0000'0001,
            //GARBAGE = 7,
            //HARD_BLOCK = 27,
            //BLINK = 31,
            //PIECE_BITS = 0x07u,
            //ITEM_BITS = 0xF8u,
            //BLINK_BIT = 0x8000u,
            //HARD_BLOCK_BIT = 0x4000u
            // 19 Items: needs 5 bits
            Mask = 0b1100'0000,
        };

        inline constexpr Block() : m_value(0) { };

        inline void color(Shape color) { m_value = static_cast<uint8_t>(color) << 8; }

        inline void add_blink() { m_value |= Blink << 8; }
        inline void reset_blink() { m_value &= ~(Blink << 8); }

        inline void add_outline(uint8_t outline) { m_value |= outline << 8; }
        inline void reset_outline() { m_value &= ~(Outline::Mask << 8); }

        inline void inc_visible_frames() { m_value++; }
        inline void reset_visible_frames() { m_value &= ~VisibleFrames::Mask; }

        inline bool filled() const { return static_cast<uint8_t>(m_value >> 8) & (Outline::Mask | Shapes::Mask); }
        inline bool empty() const { return !filled(); }

        inline bool blink() const { return static_cast<uint8_t>(m_value >> 8) & Blink; }

        inline Shape color() const { return static_cast<Shape>(static_cast<uint8_t>(m_value >> 8) & Shapes::Mask); }
        inline uint8_t outline() const { return static_cast<uint8_t>(static_cast<uint8_t>(m_value >> 8) & Outline::Mask); }
        inline uint16_t visible_frames() const { return m_value & VisibleFrames::Mask; }

        inline bool outline_left() const { return outline() & Outline::Left; }
        inline bool outline_right() const { return outline() & Outline::Right; }
        inline bool outline_top() const { return outline() & Outline::Top; }
        inline bool outline_bottom() const { return outline() & Outline::Bottom; }

        inline uint16_t raw() const { return m_value; }

    private:
        inline constexpr Block(uint16_t value) : m_value(value) { };

        uint16_t m_value;
};

#endif
