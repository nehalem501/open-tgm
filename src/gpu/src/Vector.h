/* Vector.h - GPU */

#ifndef GPU_VECTOR_H
#define GPU_VECTOR_H

#include <vector>

template<class T>
class Vector {
    public:
        void resize(size_t new_size) {
            m_data.resize(new_size);
        }

        void push(const T& elem) {
            m_data.push_back(elem);
        }

        T& operator[](size_t index) {
            return m_data[index];
        }

        const T& operator[](size_t index) const {
            return m_data[index];
        }

        void insert(size_t position, const T& elem) {
            if (position >= size()) {
                push(elem);
            } else {
                m_data.insert(m_data.begin() + position, elem);
            }
        }

        size_t size() const { return m_data.size(); }

    private:
        std::vector<T> m_data;
};

#endif // GPU_VECTOR_H
