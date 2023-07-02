/* Home.h */

#ifndef HOME_H
#define HOME_H

#include <stdint.h>
#include <TargetTypes.h>
#include <Global.h>
#include <Position.h>
#include <Text.h>
#include <Enums.h>
#include <HomeImpl.h>

#define PRESS_START_POSITION Position(screen.width / 2, 2 * (screen.height / 3))

class Home {
    public:
        Home();

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            m_start.resize(PRESS_START_POSITION);
        }
        #endif

        void update(SceneState& scene_state);

    private:
        Text m_start;
        uint8_t m_start_timer;
};

#endif // HOME_H
