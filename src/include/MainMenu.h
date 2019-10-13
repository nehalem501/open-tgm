/* MainMenu.h */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <Home.h>
#include <Game.h>
#include <ChooseMode.h>
#include <Settings.h>
#include <Background.h>

namespace MainMenuState {
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
        SETTINGS
    };
}

class MainMenu {
    public:
        MainMenu();

        void draw();

        void init();

        void update();

        void home();
        void choose_mode();
        void ingame();

    private:
        int m_state;
        int m_mode;

        Home m_home;
        Game m_game;
        ChooseMode m_choose_mode;
        Settings m_settings;
        Background m_background;
};

#endif // MAIN_MENU_H
