/* PlayerImpl.cpp - Dummy */

#include <Player.h>
#include "PlayerImpl.h"

PlayerImpl::PlayerImpl(Player& player, Position& position) :
        m_player(player),
        m_position(position) {

}

void PlayerImpl::update_piece_type() {

}

void PlayerImpl::update_piece_position() {

}

void PlayerImpl::update_piece_lock_animation(
    unsigned int /*lock*/,
    unsigned int /*max*/) {

}

void PlayerImpl::update_piece_reset_lock() {

}

void PlayerImpl::update_ghost_type() {

}

void PlayerImpl::update_ghost_position() {

}

void PlayerImpl::update_next_type() {

}

void PlayerImpl::render() const {
    if (m_player.draw_ghost()) {
        // Draw ghost piece
    }

    if (m_player.draw_piece()) {
        // Draw active piece
    }

    // Draw next piece
}
