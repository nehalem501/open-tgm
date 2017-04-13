/* menu.h */

#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include "game.h"
#include "background.h"
#include "home.h"
#include "choosemode.h"


namespace MenuState {
    enum {
        HOME = 0,
        CHOOSE_PLAYER,
        NEW_PLAYER,
        LOAD_PLAYER,
        CHOOSE_MODE,
        START_GAME,
        GAME_READY,
        GAME_GO,
        INGAME,
        GAME_OVER,
        SETTINGS_LIST,
        SETTINGS_INPUT_TEST,
        SETTINGS_INPUT_SET,
        SETTINGS_GAME_SET
    };
}

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Menu : public sf::Drawable {
#else
class Menu {
#endif
    public:
        Menu();
        
        void initGraphics();
        
        void update();

        void home();
        void chooseMode();
        void ingame();

        int8_t m_state;
        
    private:
        Home m_home;
        ChooseMode m_chooseMode;
        
    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
    #endif // TARGET_SFML
    #ifdef TARGET_PSP
    public:
        void draw();
    private:
    #endif
    #ifdef TARGET_GBA
    public:
        void draw();
    private:
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};

#endif
