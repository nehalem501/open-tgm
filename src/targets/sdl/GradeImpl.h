/* GradeImpl.h - SDL */

#ifndef GRADE_SDL_H
#define GRADE_SDL_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
