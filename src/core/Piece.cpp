/* Piece.cpp */

#include <Block.h>
#include <Shapes.h>
#include <Utils.h>
#include <Coordinates.h>
#include <Field.h>
#include <Piece.h>

Piece::Piece() :
        m_coordinates(0, 0),
        m_orientation(),
        m_type(Shape::Empty) {
}

void Piece::spawn(Shape type) {
    constexpr Coordinates SPAWN_COORDINATES = Coordinates(3, 1);
    m_type = type;
    m_orientation.reset();
    m_coordinates = SPAWN_COORDINATES;
}

/* Lock piece to stack */
void Piece::put(Field &field) {
    const uint_fast8_t size = m_type == Shape::I ? Shapes::Size : Shapes::SmallSize;
    for (uint_fast8_t x = 0; x < size; x++) {
        for (uint_fast8_t y = 0; y < size; y++) {
            if (ShapesData::get(m_type).get_block(x, y, m_orientation.value()) != Shape::Empty) {
                Block& b = field.block_mut(m_coordinates.x + x, m_coordinates.y + y);
                b.color(m_type);
                b.add_blink();
            }
        }
    }
}

/* Check if valid position */
bool Piece::check_move(const Field &field, const Coordinates& move, const Rotation rotation) const {
    const Coordinates coordinates = move + m_coordinates;
    Orientation o = m_orientation;
    o.rotate(rotation);
    const uint_fast8_t orientation = o.value();
    const uint_fast8_t size = m_type == Shape::I ? Shapes::Size : Shapes::SmallSize;
    for (uint_fast8_t x = 0; x < size; x++) {
        for (uint_fast8_t y = 0; y < size; y++) {
            if (ShapesData::get(m_type).get_block(x, y, orientation) != Shape::Empty) {
                const uint_fast8_t field_x = (uint_fast8_t) coordinates.x + (uint_fast8_t) x;
                const uint_fast8_t field_y = (uint_fast8_t) coordinates.y + (uint_fast8_t) y;
                if (field_x >= field.width()) {
                    return false;
                }
                if (field_y >= field.height()) {
                    return false;
                }
                if (field.block(field_x, field_y).filled()) {
                    return false;
                }
            }
        }
    }

    // TODO multiplayer

    return true;
}

/* Get Y coordinate of ghost piece */
uint_fast8_t Piece::get_ghost_y(const Field &field) const {
    bool can_go_down = true;
    uint_fast8_t i;
    for (i = 1; can_go_down; i++) {
        can_go_down = check_move(field, Coordinates(0, i), Rotation::None);
    }

    // TODO multiplayer

    return m_coordinates.y + i - 2;
}

/* Move piece in left or right direction */
void Piece::move_leftright(const Field& field, int *ghost_y, uint_fast8_t amount) {
    if (check_move(field, Coordinates(amount, 0), Rotation::None)) {
        m_coordinates.x += amount;
        *ghost_y = get_ghost_y(field);
    }
}

/* Move piece downwards */
uint_fast8_t Piece::move_down(uint_fast8_t ghost_y, uint_fast8_t amount) {
    uint_fast8_t old_pos_y = m_coordinates.y;

    if (ghost_y >= (m_coordinates.y + amount)) {
        m_coordinates.y += amount;
    } else {
        m_coordinates.y = ghost_y;
    }

    return m_coordinates.y - old_pos_y;
}

/* Rotate piece including wallkicks */
void Piece::rotate_kick(const Field& field, int */*ghost_y*/, Rotation /*rotation*/) {
    // Center column disables rotation with T piece
    if (m_type == Shape::T) {
        int x = m_coordinates.x - 1;
        if (x >= 0 || x < (int) field.width()) {
            int y = m_coordinates.y - 1;
            if (y < (int) field.height() && y >= 0) {
                if (field.block(x, y).filled()) {
                    return;
                }
            }
        }
    }

    // Check basic rotation
    //int new_orientation = modulo(m_orientation + rotation, 4);
    /*if (stack.check_player_move(*this, Coordinates(0, 0), rotation)) {
        orientation(new_orientation);
        *ghost_y = stack.get_ghost_y(*this);
    } else if (m_type != Shape::I && m_type != Shape::O) {
        // No wallkicks for I and O pieces

        // Check if center column occupied (J and L pieces case)
        if (m_type == Shape::J || m_type == Shape::L) {
            int x = 0;
            int y = 0;

            // check if J wallkick is still possible
            if (m_type == Shape::J) {
                x = m_coordinates.x;
                y = m_coordinates.y - 1;
                if (x >= 0 || x < stack.width()) {
                    if (y < stack.height() && y >= 0) {
                        if (stack.block(x, y).filled()) {
                            // Check wallkick one block to the right
                            if (stack.check_player_move(*this, Coordinates(1, 0), rotation)) {
                                move(1, 0);
                                rotate(new_orientation);
                                *ghost_y = stack.get_ghost_y(*this);
                            }

                            // Check wallkick one block to the left
                            if (stack.check_player_move(*this, Coordinates(-1, 0), rotation)) {
                                move(-1, 0);
                                rotate(new_orientation);
                                *ghost_y = stack.get_ghost_y(*this);
                            }

                            return;
                        }
                    }
                }
            }

            // check if L wallkick is still possible
            if (m_type == Shape::L) {
                x = m_coordinates.x - 2;
                y = m_coordinates.y - 1;
                if (x >= 0 || x < stack.width()) {
                    if (y < stack.height() && y >= 0) {
                        if (stack.block(x, y).filled()) {
                            // Check wallkick one block to the right
                            if (stack.check_player_move(*this, Coordinates(1, 0), rotation)) {
                                move(1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack.get_ghost_y(*this);
                            }

                            // Check wallkick one block to the left
                            if (stack.check_player_move(*this, Coordinates(-1, 0), rotation)) {
                                move(-1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack.get_ghost_y(*this);
                            }

                            return;
                        }
                    }
                }
            }

            // Check for wallkicks exceptions
            x = m_coordinates.x - 1;

            if (x >= 0 || x < stack.width()) {
                y = m_coordinates.y - 1;
                if (y < stack.height() && y >= 0) {
                    if (stack.block(x, y).filled()) {
                        return;
                    }
                }

                y = m_coordinates.y;
                if (y < stack.height() && y >= 0) {
                    if (stack.block(x, y).filled()) {
                        return;
                    }
                }

                y = m_coordinates.y + 1;
                if (y < stack.height() && y >= 0) {
                    if (stack.block(x, y).filled()) {
                        return;
                    }
                }
            }
        }

        // Check wallkick one block to the right
        if (stack.check_player_move(*this, Coordinates(1, 0), rotation)) {
            move(1, 0);
            orientation(new_orientation);
            *ghost_y = stack.get_ghost_y(*this);
        }

        // Check wallkick one block to the left
        else if (stack.check_player_move(*this, Coordinates(-1, 0), rotation)) {
            move(-1, 0);
            orientation(new_orientation);
            *ghost_y = stack.get_ghost_y(*this);
        }
    }*/
}
