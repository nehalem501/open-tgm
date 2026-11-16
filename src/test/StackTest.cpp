/* StackTest.cpp */

#include <Stack.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Stack init", "[stack]") {
    Position parent(16, 42);
    Stack stack(parent);

    stack.init(parent, 10, 22);

    REQUIRE(stack.position().x == 16);
    REQUIRE(stack.position().y == 42);

    REQUIRE(stack.field().width() == 10);
    REQUIRE(stack.field().height() == 22);

    for (size_t i = 0; i < 22; i++) {
        REQUIRE(stack.field().empty_line(i) == true);
    }
}

TEST_CASE("Stack init doubles", "[stack]") {
    Position parent(8, 5);
    Stack stack(parent);

    stack.init(parent, 14, 22);

    REQUIRE(stack.position().x == 8);
    REQUIRE(stack.position().y == 5);

    REQUIRE(stack.field().width() == 14);
    REQUIRE(stack.field().height() == 22);

    for (size_t i = 0; i < 22; i++) {
        REQUIRE(stack.field().empty_line(i) == true);
    }
}