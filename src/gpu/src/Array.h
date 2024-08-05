/* Array.h - GPU */

#ifndef GPU_ARRAY_H
#define GPU_ARRAY_H

#include <stddef.h>
#include <vector>

template<class T, size_t N>
class Array {
    public:
        inline T& operator[](size_t index) {
            return m_data[index];
        }

        inline const T& operator[](size_t index) const {
            return m_data[index];
        }

        size_t size() const { return N; }

    private:
        T m_data[N];
};

#endif // GPU_ARRAY_H
