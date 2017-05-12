/* PlayerImpl.h - SFML */

#ifndef PLAYER_SFML_H
#define PLAYER_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BasePlayer.h>

class PlayerImpl : public BasePlayer, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        void updateSize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray m_next_vertices;
        sf::VertexArray m_piece_vertices;
        sf::VertexArray m_ghost_vertices;
};

#endif
