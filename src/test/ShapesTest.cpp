/* ShapesTest.cpp */

#include <Shapes.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>
#include "helpers.h"

TEST_CASE("Shapes data: I", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& I = ShapesData::get(Shape::I);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 0, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(I.get(0)), RangeEquals(to_vector_16(Shape::I, s1)));

    const std::vector<uint8_t> s2 = {
        0, 0, 1, 0,
        0, 0, 1, 0,
        0, 0, 1, 0,
        0, 0, 1, 0,
    };
    CHECK_THAT(to_vector_16(I.get(1)), RangeEquals(to_vector_16(Shape::I, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 0, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(I.get(2)), RangeEquals(to_vector_16(Shape::I, s3)));

    const std::vector<uint8_t> s4 = {
        0, 0, 1, 0,
        0, 0, 1, 0,
        0, 0, 1, 0,
        0, 0, 1, 0,
    };
    CHECK_THAT(to_vector_16(I.get(3)), RangeEquals(to_vector_16(Shape::I, s4)));
}

TEST_CASE("Shapes data: Z", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& Z = ShapesData::get(Shape::Z);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        1, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(Z.get(0)), RangeEquals(to_vector_16(Shape::Z, s1)));

    const std::vector<uint8_t> s2 = {
        0, 0, 1, 0,
        0, 1, 1, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(Z.get(1)), RangeEquals(to_vector_16(Shape::Z, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        1, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(Z.get(2)), RangeEquals(to_vector_16(Shape::Z, s3)));

    const std::vector<uint8_t> s4 = {
        0, 0, 1, 0,
        0, 1, 1, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(Z.get(3)), RangeEquals(to_vector_16(Shape::Z, s4)));
}

TEST_CASE("Shapes data: S", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& S = ShapesData::get(Shape::S);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        1, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(S.get(0)), RangeEquals(to_vector_16(Shape::S, s1)));

    const std::vector<uint8_t> s2 = {
        1, 0, 0, 0,
        1, 1, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(S.get(1)), RangeEquals(to_vector_16(Shape::S, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        1, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(S.get(2)), RangeEquals(to_vector_16(Shape::S, s3)));

    const std::vector<uint8_t> s4 = {
        1, 0, 0, 0,
        1, 1, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(S.get(3)), RangeEquals(to_vector_16(Shape::S, s4)));
}

TEST_CASE("Shapes data: J", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& J = ShapesData::get(Shape::J);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        1, 1, 1, 0,
        0, 0, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(J.get(0)), RangeEquals(to_vector_16(Shape::J, s1)));

    const std::vector<uint8_t> s2 = {
        0, 1, 1, 0,
        0, 1, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(J.get(1)), RangeEquals(to_vector_16(Shape::J, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        1, 0, 0, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(J.get(2)), RangeEquals(to_vector_16(Shape::J, s3)));

    const std::vector<uint8_t> s4 = {
        0, 1, 0, 0,
        0, 1, 0, 0,
        1, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(J.get(3)), RangeEquals(to_vector_16(Shape::J, s4)));
}

TEST_CASE("Shapes data: L", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& L = ShapesData::get(Shape::L);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        1, 1, 1, 0,
        1, 0, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(L.get(0)), RangeEquals(to_vector_16(Shape::L, s1)));

    const std::vector<uint8_t> s2 = {
        0, 1, 0, 0,
        0, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(L.get(1)), RangeEquals(to_vector_16(Shape::L, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        0, 0, 1, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(L.get(2)), RangeEquals(to_vector_16(Shape::L, s3)));

    const std::vector<uint8_t> s4 = {
        1, 1, 0, 0,
        0, 1, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(L.get(3)), RangeEquals(to_vector_16(Shape::L, s4)));
}

TEST_CASE("Shapes data: O", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& O = ShapesData::get(Shape::O);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(O.get(0)), RangeEquals(to_vector_16(Shape::O, s1)));

    const std::vector<uint8_t> s2 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(O.get(1)), RangeEquals(to_vector_16(Shape::O, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(O.get(2)), RangeEquals(to_vector_16(Shape::O, s3)));

    const std::vector<uint8_t> s4 = {
        0, 0, 0, 0,
        0, 1, 1, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(O.get(3)), RangeEquals(to_vector_16(Shape::O, s4)));
}

TEST_CASE("Shapes data: T", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& T = ShapesData::get(Shape::T);

    const std::vector<uint8_t> s1 = {
        0, 0, 0, 0,
        1, 1, 1, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(T.get(0)), RangeEquals(to_vector_16(Shape::T, s1)));

    const std::vector<uint8_t> s2 = {
        0, 1, 0, 0,
        0, 1, 1, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(T.get(1)), RangeEquals(to_vector_16(Shape::T, s2)));

    const std::vector<uint8_t> s3 = {
        0, 0, 0, 0,
        0, 1, 0, 0,
        1, 1, 1, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(T.get(2)), RangeEquals(to_vector_16(Shape::T, s3)));

    const std::vector<uint8_t> s4 = {
        0, 1, 0, 0,
        1, 1, 0, 0,
        0, 1, 0, 0,
        0, 0, 0, 0,
    };
    CHECK_THAT(to_vector_16(T.get(3)), RangeEquals(to_vector_16(Shape::T, s4)));
}

TEST_CASE("Shapes data line", "[shapes]") {
    using Catch::Matchers::RangeEquals;

    const ShapeData& T = ShapesData::get(Shape::T);

    const std::vector<uint8_t> l1 = { 0, 0, 0, 0 };
    CHECK_THAT(to_vector_4(T.get_line(0, 2)), RangeEquals(to_vector_4(Shape::T, l1)));

    const std::vector<uint8_t> l2 = { 0, 1, 0, 0 };
    CHECK_THAT(to_vector_4(T.get_line(1, 2)), RangeEquals(to_vector_4(Shape::T, l2)));

    const std::vector<uint8_t> l3 = { 1, 1, 1, 0 };
    CHECK_THAT(to_vector_4(T.get_line(2, 2)), RangeEquals(to_vector_4(Shape::T, l3)));

    const std::vector<uint8_t> l4 = { 0, 0, 0, 0 };
    CHECK_THAT(to_vector_4(T.get_line(3, 2)), RangeEquals(to_vector_4(Shape::T, l4)));
}