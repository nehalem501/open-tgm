/* Home.h */

#ifndef HOME_H
#define HOME_H

#include <stdint.h>
#include <TargetTypes.h>
#include <Position.h>
#include <Text.h>
#include <HomeImpl.h>

class Home {
    public:
        Home(const Position& parent);

        void draw() const;

        #ifdef RESIZABLE
        void resize(const Position& parent) { m_start.resize(parent); }
        #endif

        void update(int *state);

    private:
        Text m_start;
        uint8_t m_start_timer;
};

#endif // HOME_H
