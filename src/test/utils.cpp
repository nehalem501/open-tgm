/* utils.cpp */

#include <vector>
#include <Shapes.h>

std::vector<Shape> to_vector_4(std::span<const Shape, 4> span) {
    std::vector<Shape> v;
    v.insert(v.begin(), span.begin(), span.end());
    return v;
}

std::vector<Shape> to_vector_4(Shape c, std::vector<uint8_t> s) {
    std::vector<Shape> v;
    v.resize(4);
    for (size_t i = 0; i < 4; i++) {
        if (s[i]) {
            v[i] = c;
        }
    }
    return v;
}

std::vector<Shape> to_vector_16(std::span<const Shape, 16> span) {
    std::vector<Shape> v;
    v.insert(v.begin(), span.begin(), span.end());
    return v;
}

std::vector<Shape> to_vector_16(Shape c, std::vector<uint8_t> s) {
    std::vector<Shape> v;
    v.resize(16);
    for (size_t i = 0; i < 16; i++) {
        if (s[i]) {
            v[i] = c;
        }
    }
    return v;
}