/* Field.cpp */

#include <Field.h>
#include <string.h>

void Field::reset(const uint_fast8_t width, const uint_fast8_t height) {
    m_width = width;
    m_height = height;

    memset((void*) m_data, 0, m_width * m_height * sizeof(Block));
}
