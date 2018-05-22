/* BackgroundImpl.h - PS2 */

#ifndef BACKGROUND_PS2_H
#define BACKGROUND_PS2_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
