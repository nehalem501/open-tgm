/* Home.h */

#ifndef HOME_H
#define HOME_H

#include <stdint.h>
#include <TargetTypes.h>
#include <Text.h>
#include <HomeImpl.h>

class Home {
    public:
        Home();

        void draw() const;

        void update(int *state);

    private:
        Text m_start;
        uint8_t m_start_timer;

        //HomeImpl m_implementation;
};

#endif // HOME_H
