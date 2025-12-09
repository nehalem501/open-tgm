/* PlayerImpl.cpp - GPU */

#include <Shapes.h>
#include <Player.h>
#include "TilemapEnums.h"
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
            TilemapID::BLOCKS
        ),
        m_ghost(
            position, // TODO
            player.piece().tiles(),
            ColorRGBA(0.32f, 0.32f, 0.32f, 1.0f),
            PIECE_SIZE,
            PIECE_SIZE,
            TilemapID::BLOCKS
        ),
        m_next(
            //Position(position.x + 3 * Global::tile_size, position.y - (2 * Global::tile_size + (Global::tile_size / 2))), // TODO
            position, // TODO
            PIECES[player.get_next_piece()][0],
            GPU_WHITE,
            PIECE_SIZE,
            PIECE_SIZE,
            TilemapID::BLOCKS
        ) {
    // TODO m_next position initialization doesn't work after resizing
}

void PlayerImpl::position(Position& position) {
    m_position = position;
    update_next_position();
}

void PlayerImpl::update_piece_type() {
    m_piece.update(m_player.piece().tiles());
}

void PlayerImpl::update_piece_position() {
    const Coordinates coordinates = Coordinates(-2, -1) + m_player.piece().coordinates();
    m_piece.position(m_position + coordinates.to_position());
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
    const Coordinates coordinates = Coordinates(-2, -1) + Coordinates(m_player.piece().coordinates().x, m_player.get_ghost_y());
    m_ghost.position(m_position + coordinates.to_position());
}

void PlayerImpl::update_next_type() {
    m_next.update(PIECES[m_player.get_next_piece()][0]);
}

void PlayerImpl::update_next_position() {
    const Coordinates coordinates(3, -2);
    Position position = m_position + coordinates.to_position();
    position.y -= Global::tile_size / 4;
    m_next.position(position);

    /*m_next.position(Position(
        m_position.x + 3 * Global::tile_size,
        m_position.y - (2 * Global::tile_size + (Global::tile_size / 2))));*/
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

#ifdef RESIZABLE
void PlayerImpl::resize() {
    m_piece.resize(m_position);
    m_ghost.resize(m_position);
    m_next.resize(m_position);
    update_piece_position();
    update_ghost_position();
    update_next_position();
}
#endif
