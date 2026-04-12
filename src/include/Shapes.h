/* Shape.h */

#ifndef SHAPES_H
#define SHAPES_H

#include <array>
#include <span>
#include <TargetTypes.h>
#include <Enums.h>

class ShapeData {
    public:
        enum : uint_fast8_t {
            LineSize = Shapes::Size,
            EntrySize = LineSize * Shapes::Size,
            Length = EntrySize * Shapes::Rotations
        };

        constexpr ShapeData(
            const Shape color,
            const char data[Length]
        ) : m_data(shape_definition(color, data)) {}

        inline const std::span<const Shape, EntrySize> get(uint_fast8_t orientation) const {
            return std::span<const Shape, EntrySize>(m_data.data() + EntrySize * orientation, EntrySize);
        }

        inline const std::span<const Shape, LineSize> get_line(uint_fast8_t line, uint_fast8_t orientation) const {
            return std::span<const Shape, LineSize>(m_data.data() + LineSize * line + EntrySize * orientation, EntrySize);
        }

        inline Shape get_block(uint_fast8_t x, uint_fast8_t y, uint_fast8_t orientation) const {
            return m_data[x + Shapes::Size * y + orientation * EntrySize];
        }

    private:
        ShapeData() = delete;

        const std::array<Shape, Length> m_data;

        constexpr static std::array<Shape, Length> shape_definition(
            const Shape color,
            const char data[Length])
        {
            std::array<Shape, Length> colored_data {};

            for (uint_fast8_t i = 0; i < Length; i++) {
                if (data[i] != ' ') {
                    colored_data[i] = color;
                }
            }

            return colored_data;
        }
};

class ShapesData {
    public:
        const static ShapeData& get(Shape s) {
            switch (s) {
                case Shape::I:
                    return m_data.I;
                case Shape::Z:
                    return m_data.Z;
                case Shape::S:
                    return m_data.S;
                case Shape::J:
                    return m_data.J;
                case Shape::L:
                    return m_data.L;
                case Shape::O:
                    return m_data.O;
                case Shape::T:
                    return m_data.T;
                default:
                    return m_data.Empty;
            }
        }

    private:
        const static ShapesData m_data;

        const ShapeData Empty;
        const ShapeData I;
        const ShapeData Z;
        const ShapeData S;
        const ShapeData J;
        const ShapeData L;
        const ShapeData O;
        const ShapeData T;

        constexpr ShapesData() :
            Empty(Shape::Empty,
                "    "
                "    "
                "    "
                "    "

                "    "
                "    "
                "    "
                "    "

                "    "
                "    "
                "    "
                "    "

                "    "
                "    "
                "    "
                "    "
            ),
            I(Shape::I,
                "    "
                "XXXX"
                "    "
                "    "

                "  X "
                "  X "
                "  X "
                "  X "

                "    "
                "XXXX"
                "    "
                "    "

                "  X "
                "  X "
                "  X "
                "  X "
            ),
            Z(Shape::Z,
                "    "
                "XX  "
                " XX "
                "    "

                "  X "
                " XX "
                " X  "
                "    "

                "    "
                "XX  "
                " XX "
                "    "

                "  X "
                " XX "
                " X  "
                "    "
            ),
            S(Shape::S,
                "    "
                " XX "
                "XX  "
                "    "

                "X   "
                "XX  "
                " X  "
                "    "

                "    "
                " XX "
                "XX  "
                "    "

                "X   "
                "XX  "
                " X  "
                "    "
            ),
            J(Shape::J,
                "    "
                "XXX "
                "  X "
                "    "

                " XX "
                " X  "
                " X  "
                "    "

                "    "
                "X   "
                "XXX "
                "    "

                " X  "
                " X  "
                "XX  "
                "    "
            ),
            L(Shape::L,
                "    "
                "XXX "
                "X   "
                "    "

                " X  "
                " X  "
                " XX "
                "    "

                "    "
                "  X "
                "XXX "
                "    "

                "XX  "
                " X  "
                " X  "
                "    "
            ),
            O(Shape::O,
                "    "
                " XX "
                " XX "
                "    "

                "    "
                " XX "
                " XX "
                "    "

                "    "
                " XX "
                " XX "
                "    "

                "    "
                " XX "
                " XX "
                "    "
            ),
            T(Shape::T,
                "    "
                "XXX "
                " X  "
                "    "

                " X  "
                " XX "
                " X  "
                "    "

                "    "
                " X  "
                "XXX "
                "    "

                " X  "
                "XX  "
                " X  "
                "    "
            )
        {}
};

#endif // SHAPES_H
