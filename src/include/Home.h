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

class Home {
    public:
        Home(const Size& parent_size);

        void draw() const;

        #ifdef RESIZABLE
        inline void resize(const Size& parent_size) {
            m_start.resize(compute_position(parent_size));
        }
        #endif

        void update(SceneState& scene_state);

    private:
        Text m_start;
        uint8_t m_start_timer;

        inline static Position compute_position(const Size& parent_size) {
            return Position(parent_size.width / 2, parent_size.height * 2 / 3);
        }
};

#endif // HOME_H
