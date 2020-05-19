/* Scene.h */

#ifndef SCENE_H
#define SCENE_H

#include <Size.h>
#include <Home.h>
#include <GameView.h>
#include <Settings.h>
#include <Background.h>

namespace SceneState {
    enum {
        HOME = 0,
        GAME,
        SETTINGS
    };
}

#define PRESS_START_POSITION Position(screen.width / 2, 2 * (screen.height / 3))

class Scene {
    public:
        Scene();

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            m_home.resize(PRESS_START_POSITION);
            m_game_view.resize();
            m_settings.resize();
            m_background.resize();
        }
        #endif

        void update();

        void home();
        void choose_mode();
        void ingame();

    private:
        int m_state;

        Home m_home;
        GameView m_game_view;
        Settings m_settings;
        Background m_background;
};

#endif // SCENE_H
