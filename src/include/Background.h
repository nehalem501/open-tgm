/* Background.h */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <BackgroundImpl.h>

class Background {
    public:
        Background();

        void draw() const;

        void go_to_options() { m_options = true; };
        void go_to_background() { m_options = false; };

    private:
        bool m_options;

        BackgroundImpl m_implementation;
};

#endif // BACKGROUND_H
