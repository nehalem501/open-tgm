/* FieldTest.cpp */

#include <Field.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Field init", "[field]") {
    Field f;

    f.reset(0, 0);
    REQUIRE(f.width() == 0);
    REQUIRE(f.height() == 0);

    f.reset(10, 20);
    REQUIRE(f.width() == 10);
    REQUIRE(f.height() == 20);

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 20; j++) {
            Coordinates c(i, j);
            REQUIRE(f.block(i, j).empty() == true);
            REQUIRE(f.block(c).empty() == true);
        }
    }
}

TEST_CASE("Field block", "[field]") {
    Field f;
    f.reset(10, 20);

    REQUIRE(f.width() == 10);
    REQUIRE(f.height() == 20);

    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 20; j++) {
            Coordinates c(i, j);
            f.block_mut(i, j).color(Shape::T);
            REQUIRE(f.block(i, j).filled() == true);
            REQUIRE(f.block(c).filled() == true);
        }
    }
}

TEST_CASE("Field empty line", "[field]") {
    Field f;
    f.reset(10, 20);
    for (size_t i = 0; i < 20; i++) {
        REQUIRE(f.empty_line(i) == true);
    }
}

TEST_CASE("Field filled line", "[field]") {
    Field f;
    f.reset(10, 20);
    for (size_t i = 0; i < 10; i++) {
        for (size_t j = 0; j < 20; j++) {
            f.block_mut(i, j).color(Shape::T);
        }
    }
    for (size_t i = 0; i < 20; i++) {
        REQUIRE(f.filled_line(i) == true);
    }
}