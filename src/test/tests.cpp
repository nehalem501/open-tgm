#include <catch2/catch_test_macros.hpp>

// TODO: remove and implement actual tests
unsigned int factorial(unsigned int number) {
    return number <= 1 ? number : factorial(number - 1) * number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial(1) == 1 );
    REQUIRE( factorial(2) == 2 );
    REQUIRE( factorial(3) == 6 );
    REQUIRE( factorial(10) == 3628800 );
}