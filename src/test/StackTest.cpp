/* StackTest.cpp */

#include <Mode.h>
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

TEST_CASE("Stack start", "[stack]") {
    Position parent(7, 4);
    Stack stack(parent);

    RawMode r = {
        .width = 5,
        .height = 10
    };
    Mode mode(&r);

    stack.start_game(mode);

    REQUIRE(stack.position().x == 7);
    REQUIRE(stack.position().y == 4);

    REQUIRE(stack.field().width() == 5);
    REQUIRE(stack.field().height() == 10);

    for (size_t i = 0; i < 10; i++) {
        REQUIRE(stack.field().empty_line(i) == true);
    }
}