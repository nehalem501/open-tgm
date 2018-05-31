/* GradeImpl.h - SDL2 */

#ifndef GRADE_SDL2_H
#define GRADE_SDL2_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
