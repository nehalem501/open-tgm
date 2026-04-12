/* OrientationTest.cpp */

#include <Orientation.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>

TEST_CASE("Orientation init", "[orientation]") {
    Orientation o;
    REQUIRE(o.value() == 0);
}

TEST_CASE("Orientation rotation", "[orientation]") {
    Orientation o;
    REQUIRE(o.value() == 0);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 1);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 0);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 3);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 2);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 1);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 0);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 3);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 0);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 1);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 2);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 3);

    o.rotate(Rotation::Left);
    REQUIRE(o.value() == 0);

    o.rotate(Rotation::Right);
    REQUIRE(o.value() == 3);

    o.reset();
    REQUIRE(o.value() == 0);
}