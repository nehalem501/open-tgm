/* Scene.cpp */

#include <stddef.h>
#include <Global.h>
#include <Home.h>
#include <Input.h>
#include <GameView.h>
#include <Background.h>
#include <Debug.h>
#include <Scene.h>

Scene::Scene() : m_state(SceneState::HOME) {
    printd(DebugCategory::SCENE, "Scene constructor");
}

void Scene::update() {
    input.poll_inputs();

    switch(m_state) {
        case SceneState::HOME:
            if (input.settings()) {
                m_state = SceneState::SETTINGS;
                m_background.go_to_options();
                return;
            }
            m_home.update(m_state);
            break;

        case SceneState::GAME:
            // Update logic
            m_game_view.update(m_state);

            //m_game.update_graphics();
            //ingame();
            break;

        case SceneState::SETTINGS:
            m_settings.update(m_state, &m_background);
            break;
    }
}

void Scene::draw() const {
    m_background.draw();
    switch(m_state) {
        case SceneState::HOME:
            m_home.draw();
            break;

        case SceneState::GAME:
            // TODO 2 players
            m_game_view.draw();
            break;

        case SceneState::SETTINGS:
            m_settings.draw();
            break;
    }
}
