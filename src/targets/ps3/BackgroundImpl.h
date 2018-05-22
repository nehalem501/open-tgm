/* BackgroundImpl.h - PS3 */

#ifndef BACKGROUND_PS3_H
#define BACKGROUND_PS3_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
