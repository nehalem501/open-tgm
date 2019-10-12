/* Piece.cpp */

#include <Global.h>
#include <Shapes.h>
#include <Utils.h>
#include <Stack.h>
#include <Piece.h>

Piece::Piece() : m_type(0), m_orientation(0), m_pos_x(0), m_pos_y(0) {
}

Piece::Piece(tiles_t type, int orientation) : m_type(type),
                                              m_orientation(orientation),
                                              m_pos_x(0), m_pos_y(0) {
}

Piece::Piece(tiles_t type, int orientation, int pos_x, int pos_y) :
    m_type(type), m_orientation(orientation),
    m_pos_x(pos_x), m_pos_y(pos_y) {
}

/* Lock piece to stack */
void Piece::locked(Stack *stack) {
    int pos_x = m_pos_x - 2;
    int pos_y = m_pos_y - 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (PIECES[m_type][m_orientation][j][i] > 0) {
                int x = pos_x + i;
                int y = pos_y + j;
                stack->m_field[x + stack->m_width * y] = (m_type + 1) | Block::BLINK_BIT;
            }
        }
    }
}

/* Move piece to left or right direction */
void Piece::move_leftright(Stack *stack, int *ghost_y, int amount) {
    if(stack->check_player_move(this, amount, 0, 0)) {
        m_pos_x += amount;
        *ghost_y = stack->get_ghost_y(this);
    }
}

/* Move piece downwards */
int Piece::move_down(int ghost_y, int amount) {
    int old_pos_y = m_pos_y;

    if (ghost_y >= (m_pos_y + amount)) {
        m_pos_y += amount;
    } else {
        m_pos_y = ghost_y;
    }

    return m_pos_y - old_pos_y;
}

/* Rotate piece including wallkicks */
void Piece::rotate_kick(Stack *stack, int *ghost_y, int rotation) {
    int new_orientation = modulo(m_orientation + rotation, 4);

    // Center column disables rotation with T piece
    if (m_type == Shape::T) {
        int x = m_pos_x - 1;
        if (x >= 0 || x < stack->m_width) {
            int y = m_pos_y - 1;
            if (y < stack->m_height && y >= 0) {
                if (stack->m_field[x + y * stack->m_width] > 0) {
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
                x = m_pos_x;
                y = m_pos_y - 1;
                if (x >= 0 || x < stack->m_width) {
                    if (y < stack->m_height && y >= 0) {
                        if (stack->m_field[x + y * stack->m_width] > 0) {
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
                x = m_pos_x - 2;
                y = m_pos_y - 1;
                if (x >= 0 || x < stack->m_width) {
                    if (y < stack->m_height && y >= 0) {
                        if (stack->m_field[x + y * stack->m_width] > 0) {
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
            x = m_pos_x - 1;

            if (x >= 0 || x < stack->m_width) {
                y = m_pos_y - 1;
                if (y < stack->m_height && y >= 0) {
                    if (stack->m_field[x + y * stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_pos_y;
                if (y < stack->m_height && y >= 0) {
                    if (stack->m_field[x + y * stack->m_width] > 0) {
                        return;
                    }
                }

                y = m_pos_y + 1;
                if (y < stack->m_height && y >= 0) {
                    if (stack->m_field[x + y * stack->m_width] > 0) {
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
