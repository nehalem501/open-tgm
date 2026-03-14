/* PositionTest.cpp */

#include <Position.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Position init", "[position]") {
    Position position(42, 256);

    REQUIRE(position.x == 42);
    REQUIRE(position.y == 256);
}

TEST_CASE("Position add", "[position]") {
    Position p1(3, 2);
    Position p2(7, 5);

    Position add1 = p1 + p2;
    Position add2 = p2 + p1;

    REQUIRE(add1.x == 10);
    REQUIRE(add1.x == 10);
    REQUIRE(add2.y == 7);
    REQUIRE(add2.y == 7);
}

TEST_CASE("Position equals", "[position]") {
    Position p1(1, 2);
    Position p2(1, 2);
    Position p3(2, 3);

    bool result1 = p1 == p2;
    bool result2 = p1 == p3;
    bool result3 = p1 != p2;
    bool result4 = p1 != p3;

    REQUIRE(result1 == true);
    REQUIRE(result2 == false);
    REQUIRE(result3 == false);
    REQUIRE(result4 == true);
}