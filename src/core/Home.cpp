/* Home.cpp */

#include <TargetTypes.h>
#include <Global.h>
#include <Input.h>
#include <Text.h>
#include <Scene.h>
#include <Debug.h>
#include <Home.h>

Home::Home() :
        m_start(
            PRESS_START_POSITION,
            Coordinates(0, 0),
            Layouts::CENTERED,
            TextColor::WHITE,
            "PRESS START"),
        m_start_timer(90) {
    printd(DebugCategory::SCENE, "Home screen constructor");
}

void Home::update(SceneState& scene_state) {
    m_start_timer += 2;

    if (input.start()) {
        scene_state = SceneState::GAME;
    }
}

void Home::draw() const {
    if (m_start_timer > 90) {
        m_start.draw();
    }
}
