/* GradeImpl.h - Vulkan */

#ifndef GRADE_VULKAN_H
#define GRADE_VULKAN_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
