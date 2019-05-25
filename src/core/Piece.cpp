/* Piece.cpp */

#include <Global.h>
#include <Shapes.h>
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
