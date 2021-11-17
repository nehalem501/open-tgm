/* Vector.h - GPU */

#ifndef GPU_VECTOR_H
#define GPU_VECTOR_H

#include <stdlib.h>

template<class T>
class Vector {
    public:
        constexpr Vector() : m_data(NULL), m_capacity(0), m_size(0) { }
        Vector(size_t n) : m_data(malloc(sizeof(T) * n)), m_capacity(n), m_size(0) { }

        ~Vector() {
            if (m_data != NULL) {
                free(m_data);
            }
        }

        void reserve(size_t new_size) {
            if (new_size > m_capacity) {
                // TODO optimize
                m_data = (T*) realloc(m_data, sizeof(T) * new_size);
                m_capacity = new_size;
            }
        }

        void resize(size_t new_size) {
            reserve(new_size);
            m_size = new_size;
        }

        void push(const T& elem) {
            reserve(m_size + 1);
            m_data[m_size] = elem;
            m_size++;
        }

        T& operator[](size_t index) const {
            return m_data[index];
        }

        void insert(size_t position, const T& elem) {
            if (position >= m_size) {
                push(elem);
            } else {
                reserve(m_size + 1);
                memmove(&m_data[position + 1], &m_data[position], sizeof(T) * (m_size - position));
                m_data[position] = elem;
            }
        }

        size_t size() const { return m_size; }
        size_t capacity() const { return m_capacity; }

    private:
        T* m_data;
        size_t m_capacity, m_size;
};

#endif // GPU_VECTOR_H
