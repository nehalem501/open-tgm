/* PlayerImpl.cpp - GPU */

#include <Shapes.h>
#include <Player.h>
#include "PlayerImpl.h"

PlayerImpl::PlayerImpl(Player& player, Position& position) :
        m_player(player),
        m_position(position),
        m_piece(
            position, // TODO
            player.piece().tiles(),
            GPU_WHITE, // TODO lock anim
            PIECE_SIZE,
            PIECE_SIZE,
            TexturesID::BLOCKS
        ),
        m_ghost(
            position, // TODO
            player.piece().tiles(),
            ColorRGBA(0.32f, 0.32f, 0.32f, 1.0f),
            PIECE_SIZE,
            PIECE_SIZE,
            TexturesID::BLOCKS
        ),
        m_next(
            Position(position.x + 3 * tile_size, ((float) position.y) - (tile_size) * 2.5f), // TODO
            PIECES[player.get_next_piece()][0],
            GPU_WHITE,
            PIECE_SIZE,
            PIECE_SIZE,
            TexturesID::BLOCKS
        ) {

}

void PlayerImpl::update_piece_type() {
    m_piece.update(m_player.piece().tiles());
}

void PlayerImpl::update_piece_position() {
    m_piece.position(
        Position(
            m_position.x + (m_player.piece().position_x() - 2) * tile_size,
            m_position.y + (m_player.piece().position_y() - 1) * tile_size));
}

void PlayerImpl::update_piece_lock_animation(
    unsigned int lock,
    unsigned int max) {
    if (lock > 0) {
        const float l = lock;
        const float m = max;
        float v = 1.0f;

        if (l >= 2.0f * m / 5.0f)
            v = 0.82f;

        if (l >= 3.0f * m / 5.0f)
            v = 0.63f;

        if (l >= 4.0f * m / 5.0f)
            v = 0.5f;

        if (l == m)
            v = 0.38f;

        m_piece.color(ColorRGBA(v, v, v, 1.0f));
    }
}

void PlayerImpl::update_ghost_type() {
    m_ghost.update(m_player.piece().tiles());
}

void PlayerImpl::update_ghost_position() {
    m_ghost.position(
        Position(
            m_position.x + (m_player.piece().position_x() - 2) * tile_size,
            m_position.y + (m_player.get_ghost_y() - 1) * tile_size));
}

void PlayerImpl::update_next_type() {
    m_next.update(PIECES[m_player.get_next_piece()][0]);
}

void PlayerImpl::render() const {
    if (m_player.draw_ghost()) {
        m_ghost.render();
    }

    if (m_player.draw_piece()) {
        m_piece.render();
    }

    m_next.render();
}
