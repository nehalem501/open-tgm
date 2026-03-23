/* BlockTest.cpp */

#include <Block.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("Block reset", "[block]") {
    Block b;
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);

    b.color(Shape::Empty);
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);

    b.reset_outline();
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);

    b.inc_visible_frames();
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);

    for (int i = 0; i < 300; i++) {
        b.inc_visible_frames();
    }
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);

    b.reset_visible_frames();
    REQUIRE(b.filled() == false);
    REQUIRE(b.empty() == true);
}

TEST_CASE("Block color", "[block]") {
    Block b;
    REQUIRE(b.color() == Shape::Empty);

    Shape c = GENERATE(Shape::I, Shape::Z, Shape::S, Shape::J, Shape::L, Shape::O, Shape::T);
    b.color(c);
    REQUIRE(b.color() == c);

    b.add_outline(Outline::Mask);
    REQUIRE(b.color() == c);

    b.reset_outline();
    REQUIRE(b.color() == c);

    for (int i = 0; i < 300; i++) {
        b.inc_visible_frames();
    }
    REQUIRE(b.color() == c);

    b.reset_visible_frames();
    REQUIRE(b.color() == c);
}

TEST_CASE("Block outline", "[block]") {
    Block b;
    REQUIRE(b.outline() == 0);

    b.add_outline(0);
    REQUIRE(b.outline() == 0);

    b.add_outline(Outline::Mask);
    REQUIRE(b.outline() == Outline::Mask);

    b.reset_outline();
    REQUIRE(b.outline() == 0);

    b.add_outline(Outline::Left);
    REQUIRE(b.outline() == Outline::Left);

    b.reset_outline();
    b.add_outline(Outline::Right);
    REQUIRE(b.outline() == Outline::Right);

    b.reset_outline();
    b.add_outline(Outline::Top);
    REQUIRE(b.outline() == Outline::Top);

    b.reset_outline();
    b.add_outline(Outline::Bottom);
    REQUIRE(b.outline() == Outline::Bottom);

    b.add_outline(Outline::Left);
    b.add_outline(Outline::Top);
    b.add_outline(Outline::Bottom);
    b.add_outline(Outline::Right);
    REQUIRE(b.outline() == Outline::Mask);

    b.add_outline(Outline::Mask);
    b.color(Shape::Mask);
    REQUIRE(b.outline() == 0);

    b.add_outline(Outline::Mask);
    b.color(Shape::Empty);
    REQUIRE(b.outline() == 0);

    b.add_outline(Outline::Mask);
    b.color(Shape::L);
    REQUIRE(b.outline() == 0);

    b.add_outline(Outline::Mask);
    for (int i = 0; i < 300; i++) {
        b.inc_visible_frames();
    }
    REQUIRE(b.outline() == Outline::Mask);

    b.reset_visible_frames();
    REQUIRE(b.outline() == Outline::Mask);

    b.reset_outline();
    REQUIRE(b.outline() == 0);

    for (int i = 0; i < 300; i++) {
        b.inc_visible_frames();
    }
    REQUIRE(b.outline() == 0);

    b.reset_visible_frames();
    REQUIRE(b.outline() == 0);
}

TEST_CASE("Block visible frames", "[block]") {
    Block b;
    REQUIRE(b.visible_frames() == 0);

    b.inc_visible_frames();
    REQUIRE(b.visible_frames() == 1);

    for (int i = 0; i < 300; i++) {
        b.inc_visible_frames();
    }
    REQUIRE(b.visible_frames() == 301);

    b.reset_visible_frames();
    REQUIRE(b.visible_frames() == 0);
}