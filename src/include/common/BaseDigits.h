/* BaseDigits.h */

#ifndef BASE_DIGITS_H
#define BASE_DIGITS_H

#include <stdint.h>

class BaseDigits {
    public:
        BaseDigits();
    
        void init(int8_t pos_x, int8_t pos_y);
        void initGraphics();
        
        void update(uint32_t number);
        void updateGraphics();
    
    private:
        uint32_t m_value;
        int8_t m_pos_x, m_pos_y;
        bool m_has_changed;
};

#endif

