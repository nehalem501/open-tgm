/* BaseMenu.h */

#ifndef BASE_MENU_H
#define BASE_MENU_H

#include <stdint.h>
#include <Home.h>
#include <ChooseMode.h>

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

class BaseMenu {
    public:
        BaseMenu();

        void update();

        void home();
        void chooseMode();
        void ingame();

        int8_t m_state;

        Home m_home;
        ChooseMode m_chooseMode;
};

#endif
