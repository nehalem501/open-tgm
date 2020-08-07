/* GradeImpl.h - PSP */

#ifndef GRADE_PSP_H
#define GRADE_PSP_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
