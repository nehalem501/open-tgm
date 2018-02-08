/* Menu.h */

#ifndef CORE_MENU_H
#define CORE_MENU_H

#include <Home.h>
#include <ChooseMode.h>
#include <Settings.h>

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
        SETTINGS
    };
}

namespace Core {
    class Menu {
        public:
            Menu();

            void update();

            void home();
            void choose_mode();
            void ingame();

            int m_state;
            int m_mode;

            ::Home m_home;
            ::ChooseMode m_choose_mode;
            ::Settings m_settings;
    };
}

#endif
