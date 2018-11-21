/* MainMenu.h */

#ifndef CORE_MAIN_MENU_H
#define CORE_MAIN_MENU_H

#include <Home.h>
#include <Game.h>
#include <ChooseMode.h>
#include <Settings.h>
#include <Background.h>
#include <Stack.h>
#include <Frame.h>

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

namespace Core {
    class MainMenu {
        public:
            MainMenu();

            void init();

            void update();

            void home();
            void choose_mode();
            void ingame();

            int m_state;
            int m_mode;

            ::Home m_home;
            ::Game m_game;
            ::ChooseMode m_choose_mode;
            ::Settings m_settings;
            ::Background m_background;

            ::Stack m_stack1;
            ::Frame m_frame1;

            #ifdef MULTIPLAYER
            ::Stack m_stack2;
            ::Frame m_frame2;
            #endif
    };
}

#endif
