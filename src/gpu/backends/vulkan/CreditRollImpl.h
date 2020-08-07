/* CreditRollImpl.h - Vulkan */

#ifndef CREDIT_ROLL_VULKAN_H
#define CREDIT_ROLL_VULKAN_H

#include <core/CreditRoll.h>

class CreditRollImpl : public Core::CreditRoll {
    public:
        void init_graphics();
        void draw() const;
};

#endif
