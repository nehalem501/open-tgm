/* CoordinatesTest.cpp */

#include <Coordinates.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Coordinates init", "[coordinates]") {
    Coordinates coordinates(42, 127);

    REQUIRE(coordinates.x == 42);
    REQUIRE(coordinates.y == 127);
}

TEST_CASE("Coordinates add", "[coordinates]") {
    Coordinates c1(3, 2);
    Coordinates c2(7, 5);

    Coordinates add1 = c1 + c2;
    Coordinates add2 = c2 + c1;

    REQUIRE(add1.x == 10);
    REQUIRE(add1.x == 10);
    REQUIRE(add2.y == 7);
    REQUIRE(add2.y == 7);
}

TEST_CASE("Coordinates equals", "[coordinates]") {
    Coordinates c1(1, 2);
    Coordinates c2(1, 2);
    Coordinates c3(2, 3);

    bool result1 = c1 == c2;
    bool result2 = c1 == c3;
    bool result3 = c1 != c2;
    bool result4 = c1 != c3;

    REQUIRE(result1 == true);
    REQUIRE(result2 == false);
    REQUIRE(result3 == false);
    REQUIRE(result4 == true);
}

TEST_CASE("Coordinates convertion to Position", "[coordinates]") {
    int ts = Global::tile_size;
    Coordinates coordinates(2, 3);

    REQUIRE(coordinates.to_position_x() == ts * 2);
    REQUIRE(coordinates.to_position_y() == ts * 3);

    Position position = coordinates.to_position();

    REQUIRE(position.x == ts * 2);
    REQUIRE(position.y == ts * 3);
}