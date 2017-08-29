/* SettingsImpl.h - SFML */

#ifndef SETTINGS_SFML_H
#define SETTINGS_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Settings.h>

class SettingsImpl : public Core::Settings, public sf::Drawable {
    public:
        void init();
        void update(int *menustate);
        void initGraphics();
        void updateSize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
