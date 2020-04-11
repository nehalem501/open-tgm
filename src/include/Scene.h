/* Scene.h */

#ifndef SCENE_H
#define SCENE_H

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

class Scene {
    public:
        Scene();

        void draw() const;

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
