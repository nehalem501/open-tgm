/* Piece.h */

#ifndef PIECE_H
#define PIECE_H

#include <TargetTypes.h>
#include <Coordinates.h>
#include <Orientation.h>
#include <Field.h>
#include <Enums.h>

class Piece {
    public:
        Piece();

        void spawn(Shape type);
        void put(Field& field);

        inline Shape type() const { return m_type; }
        inline const Orientation orientation() const { return m_orientation; }
        inline Orientation& orientation_mut() { return m_orientation; }
        inline const Coordinates& coordinates() const { return m_coordinates; }
        inline Coordinates& coordinates_mut() { return m_coordinates; }

        inline void type(Shape type) { m_type = type; }
        inline void rotate(Rotation o) { m_orientation.rotate(o); }
        inline void position_x(int pos_x) { m_coordinates.x = pos_x; } // TODO
        inline void position_y(int pos_y) { m_coordinates.y = pos_y; }

        bool check_move(const Field &field, const Coordinates& move, const Rotation rotation) const;

        uint_fast8_t get_ghost_y(const Field &field) const;

        void move_leftright(const Field& field, int *ghost_y, uint_fast8_t amount);
        uint_fast8_t move_down(uint_fast8_t ghost_y, uint_fast8_t amount);
        void rotate_kick(const Field& field, int *ghost_y, Rotation rotation);

    private:
        uint_fast8_t get_first_collision(const Field &field, const Coordinates& move, const Rotation rotation) const;

        // TODO: store next and ghost here
        Coordinates m_coordinates;
        Orientation m_orientation;
        Shape m_type;

        inline void move(int x, int y) {
            m_coordinates.x += x;
            m_coordinates.y += y;
        }
};

#endif // PIECE_H
