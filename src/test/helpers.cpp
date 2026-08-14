/* helpers.cpp */

#include <vector>
#include <string>
#include <Field.h>
#include <Shapes.h>
#include "helpers.h"

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

std::vector<uint16_t> to_vec(const Block* data, size_t length) {
    std::vector<uint16_t> v;
    for (size_t i = 0; i < length; i++) {
        v.push_back(data[i].raw());
    }
    return v;
}

std::vector<uint16_t> to_vec(std::string str, Block value) {
    std::vector<uint16_t> v;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            v.push_back(0);
        } else {
            v.push_back(value.raw());
        }
    }
    return v;
}

void fill_line(Field& f, uint_fast8_t line, std::string s, char c) {
    for (uint_fast8_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            f.block_mut(i, line).color(Shape::S);
        }
    }
}

void fill(Field& f, std::vector<std::string> s, char c) {
    // TODO: check string length
    for (uint_fast8_t i = 0; i < s.size(); i++) {
        fill_line(f, i, s[i], c);
    }
}