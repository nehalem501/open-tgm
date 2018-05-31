/* GradeImpl.h - PSVita */

#ifndef GRADE_PSVITA_H
#define GRADE_PSVITA_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
