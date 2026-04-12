/* Field.h */

#ifndef FIELD_H
#define FIELD_H

#include <TargetTypes.h>
#include <Coordinates.h>
#include <Block.h>

class Field {
    public:
        const static uint_fast8_t MaxWidth = 10;
        const static uint_fast8_t MaxHeight = 22;

        void reset(const uint_fast8_t width, const uint_fast8_t height);

        inline const Block& block(uint_fast8_t x, uint_fast8_t y) const {
            return m_data[x + m_width * y];
        };

        inline const Block& block(const Coordinates& coordinates) const {
            return block(coordinates.x, coordinates.y);
        };

        inline Block& block_mut(uint_fast8_t x, uint_fast8_t y) {
            return m_data[x + m_width * y];
        };

        inline uint_fast8_t width() const { return m_width; };
        inline uint_fast8_t height() const { return m_height; };

        inline const Block* get_line(uint_fast8_t line) const { return m_data + line * m_width; }

        inline bool empty_line(uint_fast8_t line) const {
            for (size_t i = line * m_width; i < (line + 1u) * m_width; i++) {
                if (m_data[i].filled())
                    return false;
            }

            return true;
        };

        inline bool filled_line(const uint_fast8_t line) const {
            for (size_t i = line * m_width; i < (line + 1u) * m_width; i++) {
                if (m_data[i].empty())
                    return false;
            }

            return true;
        };

    private:
        const static size_t MaxLength = MaxWidth * MaxHeight;

        uint_fast8_t m_height, m_width;
        Block m_data[MaxLength];
};

#endif // FIELD_H
