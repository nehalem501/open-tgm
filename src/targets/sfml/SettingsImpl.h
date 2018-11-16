/* SettingsImpl.h - SFML */

#ifndef SETTINGS_SFML_H
#define SETTINGS_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Settings.h>
#include <Background.h>

class SettingsImpl : public Core::Settings, public sf::Drawable {
    public:
        void init();
        void update(int *menustate, Background *background);
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
