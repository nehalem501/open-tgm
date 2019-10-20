/* Piece.cpp */

#include <Shapes.h>
#include <Utils.h>
#include <Stack.h>
#include <Piece.h>

Piece::Piece() :
        m_position(0, 0),
        m_orientation(0),
        m_type(0) {
}

Piece::Piece(tiles_t type, int orientation) :
        m_position(0, 0),
        m_orientation(orientation),
        m_type(type) {
}

Piece::Piece(tiles_t type, int orientation, Position position) :
        m_position(position),
        m_orientation(orientation),
        m_type(type) {
}

/* Lock piece to stack */
void Piece::locked(Stack *stack) {
    int pos_x = m_position.x - 2;
    int pos_y = m_position.y - 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[m_type][m_orientation][j][i] > 0) {
                stack->update_block(
                    pos_x + i,
                    pos_y + j,
                    (m_type + 1) | Block::BLINK_BIT);
            }
        }
    }
}

/* Move piece in left or right direction */
void Piece::move_leftright(Stack *stack, int *ghost_y, int amount) {
    if(stack->check_player_move(this, amount, 0, 0)) {
        m_position.x += amount;
        *ghost_y = stack->get_ghost_y(this);
    }
}

/* Move piece downwards */
int Piece::move_down(int ghost_y, int amount) {
    int old_pos_y = m_position.y;

    if (ghost_y >= (m_position.y + amount)) {
        m_position.y += amount;
    } else {
        m_position.y = ghost_y;
    }

    return m_position.y - old_pos_y;
}

/* Rotate piece including wallkicks */
void Piece::rotate_kick(Stack *stack, int *ghost_y, int rotation) {
    int new_orientation = modulo(m_orientation + rotation, 4);

    // Center column disables rotation with T piece
    if (m_type == Shape::T) {
        int x = m_position.x - 1;
        if (x >= 0 || x < stack->width()) {
            int y = m_position.y - 1;
            if (y < stack->height() && y >= 0) {
                if (stack->block(x, y) > 0) {
                    return;
                }
            }
        }
    }

    // Check basic rotation
    if (stack->check_player_move(this, 0, 0, rotation)) {
        orientation(new_orientation);
        *ghost_y = stack->get_ghost_y(this);
    } else if (m_type != Shape::I && m_type != Shape::O) {
        // No wallkicks for I and O pieces

        // Check if center column occupied (J and L pieces case)
        if (m_type == Shape::J || m_type == Shape::L) {
            int x = 0;
            int y = 0;

            // check if J wallkick is still possible
            if (m_type == Shape::J) {
                x = m_position.x;
                y = m_position.y - 1;
                if (x >= 0 || x < stack->width()) {
                    if (y < stack->height() && y >= 0) {
                        if (stack->block(x, y) > 0) {
                            // Check wallkick one block to the right
                            if (stack->check_player_move(this, 1, 0, rotation)) {
                                move(1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack->get_ghost_y(this);
                            }

                            // Check wallkick one block to the left
                            if (stack->check_player_move(this, -1, 0, rotation)) {
                                move(-1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack->get_ghost_y(this);
                            }

                            return;
                        }
                    }
                }
            }

            // check if L wallkick is still possible
            if (m_type == Shape::L) {
                x = m_position.x - 2;
                y = m_position.y - 1;
                if (x >= 0 || x < stack->width()) {
                    if (y < stack->height() && y >= 0) {
                        if (stack->block(x, y) > 0) {
                            // Check wallkick one block to the right
                            if (stack->check_player_move(this, 1, 0, rotation)) {
                                move(1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack->get_ghost_y(this);
                            }

                            // Check wallkick one block to the left
                            if (stack->check_player_move(this, -1, 0, rotation)) {
                                move(-1, 0);
                                orientation(new_orientation);
                                *ghost_y = stack->get_ghost_y(this);
                            }

                            return;
                        }
                    }
                }
            }

            // Check for wallkicks exceptions
            x = m_position.x - 1;

            if (x >= 0 || x < stack->width()) {
                y = m_position.y - 1;
                if (y < stack->height() && y >= 0) {
                    if (stack->block(x, y) > 0) {
                        return;
                    }
                }

                y = m_position.y;
                if (y < stack->height() && y >= 0) {
                    if (stack->block(x, y) > 0) {
                        return;
                    }
                }

                y = m_position.y + 1;
                if (y < stack->height() && y >= 0) {
                    if (stack->block(x, y) > 0) {
                        return;
                    }
                }
            }
        }

        // Check wallkick one block to the right
        if (stack->check_player_move(this, 1, 0, rotation)) {
            move(1, 0);
            orientation(new_orientation);
            *ghost_y = stack->get_ghost_y(this);
        }

        // Check wallkick one block to the left
        else if (stack->check_player_move(this, -1, 0, rotation)) {
            move(-1, 0);
            orientation(new_orientation);
            *ghost_y = stack->get_ghost_y(this);
        }
    }
}
