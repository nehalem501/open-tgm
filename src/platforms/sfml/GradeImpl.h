/* GradeImpl.h - SFML */

#ifndef GRADE_SFML_H
#define GRADE_SFML_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
