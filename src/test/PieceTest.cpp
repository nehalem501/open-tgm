/* PieceTest.cpp */

#include <Piece.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>
#include "helpers.h"

TEST_CASE("Piece init", "[piece]") {
    Piece p;
    REQUIRE(p.type() == Shape::Empty);
    REQUIRE(p.orientation().value() == 0);
    REQUIRE(p.coordinates() == Coordinates(0, 0));

    p.spawn(Shape::T);
    REQUIRE(p.type() == Shape::T);
    REQUIRE(p.orientation().value() == 0);
}

TEST_CASE("Piece type", "[piece]") {
    Piece p;
    REQUIRE(p.type() == Shape::Empty);

    p.type(Shape::I);
    REQUIRE(p.type() == Shape::I);

    p.type(Shape::S);
    REQUIRE(p.type() == Shape::S);

    p.type(Shape::Z);
    REQUIRE(p.type() == Shape::Z);

    p.type(Shape::J);
    REQUIRE(p.type() == Shape::J);

    p.type(Shape::L);
    REQUIRE(p.type() == Shape::L);

    p.type(Shape::O);
    REQUIRE(p.type() == Shape::O);

    p.type(Shape::T);
    REQUIRE(p.type() == Shape::T);
}

TEST_CASE("Piece rotation", "[piece]") {
    Piece p;
    REQUIRE(p.orientation().value() == 0);

    p.rotate(Rotation::Left);
    REQUIRE(p.orientation().value() == 1);

    p.rotate(Rotation::Right);
    REQUIRE(p.orientation().value() == 0);
}



TEST_CASE("Piece put", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;

    p.spawn(Shape::I);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::I);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string i1 = "   XXXX   ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(i1, b)));
    for (size_t i = 3; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::S);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::S);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string s1 = "    XX    ";
    std::string s2 = "   XX     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::Z);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::Z);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string z1 = "   XX     ";
    std::string z2 = "    XX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::J);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::J);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string j1 = "   XXX    ";
    std::string j2 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::L);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::L);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string l1 = "   XXX    ";
    std::string l2 = "   X      ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::O);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::O);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string o1 = "    XX    ";
    std::string o2 = "    XX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(o1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(o2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }

    p.spawn(Shape::T);
    f.reset(10, 22);
    p.put(f);
    b.color(Shape::T);
    b.add_blink();
    REQUIRE(f.empty_line(0) == true);
    REQUIRE(f.empty_line(1) == true);
    std::string t1 = "   XXX    ";
    std::string t2 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t1, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t2, b)));
    for (size_t i = 4; i < 22; i++) {
        REQUIRE(f.empty_line(i) == true);
    }
}

TEST_CASE("Piece check_move", "[piece]") {
    Field f;
    Piece p;

    p.spawn(Shape::I);
    f.reset(10, 22);

    REQUIRE(p.check_move(f, Coordinates(0, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(0, 0), Rotation::Left) == true);

    REQUIRE(p.check_move(f, Coordinates(-1, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(-2, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(-3, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(-4, 0), Rotation::None) == false);

    REQUIRE(p.check_move(f, Coordinates(1, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(2, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(3, 0), Rotation::None) == true);
    REQUIRE(p.check_move(f, Coordinates(4, 0), Rotation::None) == false);

    REQUIRE(p.check_move(f, Coordinates(-1, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(-2, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(-3, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(-4, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(-5, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(-6, 0), Rotation::Left) == false);

    REQUIRE(p.check_move(f, Coordinates(1, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(2, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(3, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(4, 0), Rotation::Left) == true);
    REQUIRE(p.check_move(f, Coordinates(5, 0), Rotation::Left) == false);

    for (size_t i = 1; i < 18; i++) {
        REQUIRE(p.check_move(f, Coordinates(0, i), Rotation::Left) == true);
    }
    REQUIRE(p.check_move(f, Coordinates(0, 18), Rotation::Left) == false);

    p.spawn(Shape::T);
    f.block_mut(3, 2).color(Shape::I);
    f.block_mut(5, 2).color(Shape::I);
    REQUIRE(p.check_move(f, Coordinates(0, 0), Rotation::None) == false);
    p.rotate(Rotation::Left);
    REQUIRE(p.check_move(f, Coordinates(0, 0), Rotation::Left) == true);
}

TEST_CASE("Piece get_ghost_y", "[piece]") {
    Field f;
    Piece p;

    p.spawn(Shape::I);
    p.rotate(Rotation::Left);
    f.reset(10, 22);

    REQUIRE(p.get_ghost_y(f) == 18);

    p.coordinates_mut().y = 18;
    REQUIRE(p.check_move(f, Coordinates(0, 0), Rotation::None) == true);
    REQUIRE(p.get_ghost_y(f) == 18);
}

TEST_CASE("Piece move_leftright", "[piece]") {
    Field f;
    Piece p;

    p.spawn(Shape::I);
    f.reset(10, 22);
    f.block_mut(0, 21).color(Shape::I);

    REQUIRE(p.get_ghost_y(f) == 20);
    REQUIRE(p.coordinates().x == 3);
    REQUIRE(p.coordinates().y == 1);

    int ghost_y = 20;
    p.move_leftright(f, &ghost_y, -1);
    REQUIRE(p.coordinates().x == 2);
    REQUIRE(ghost_y == 20);

    p.move_leftright(f, &ghost_y, -1);
    REQUIRE(p.coordinates().x == 1);
    REQUIRE(ghost_y == 20);

    p.move_leftright(f, &ghost_y, -1);
    REQUIRE(p.coordinates().x == 0);
    REQUIRE(ghost_y == 19);

    p.move_leftright(f, &ghost_y, -1);
    REQUIRE(p.coordinates().x == 0);
    REQUIRE(ghost_y == 19);

    p.spawn(Shape::I);
    p.move_leftright(f, &ghost_y, 1);
    REQUIRE(p.coordinates().x == 4);
    REQUIRE(ghost_y == 20);

    p.move_leftright(f, &ghost_y, 1);
    REQUIRE(p.coordinates().x == 5);
    REQUIRE(ghost_y == 20);

    p.move_leftright(f, &ghost_y, 1);
    REQUIRE(p.coordinates().x == 6);
    REQUIRE(ghost_y == 20);

    p.move_leftright(f, &ghost_y, 1);
    REQUIRE(p.coordinates().x == 6);
    REQUIRE(ghost_y == 20);
}


TEST_CASE("Piece rotate_kick basic rotation I", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::I);
    b.color(Shape::I);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string i01 = "   XXXX   ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(i01, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string i11 = "     X    ";
    std::string i12 = "     X    ";
    std::string i13 = "     X    ";
    std::string i14 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(i11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(i12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(i13, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(i14, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string i21 = "     X    ";
    std::string i22 = "     X    ";
    std::string i23 = "     X    ";
    std::string i24 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(i21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(i22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(i23, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(i24, b)));
}

TEST_CASE("Piece rotate_kick basic rotation Z", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::Z);
    b.color(Shape::Z);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string z01 = "   XX     ";
    std::string z02 = "    XX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z02, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string z11 = "     X    ";
    std::string z12 = "    XX    ";
    std::string z13 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(z11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z13, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string z21 = "     X    ";
    std::string z22 = "    XX    ";
    std::string z23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(z21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z23, b)));
}

TEST_CASE("Piece rotate_kick basic rotation S", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::S);
    b.color(Shape::S);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string s01 = "    XX    ";
    std::string s02 = "   XX     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s02, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string s11 = "   X      ";
    std::string s12 = "   XX     ";
    std::string s13 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(s11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s13, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string s21 = "   X      ";
    std::string s22 = "   XX     ";
    std::string s23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(s21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s23, b)));
}

TEST_CASE("Piece rotate_kick basic rotation J", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::J);
    b.color(Shape::J);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string j01 = "   XXX    ";
    std::string j02 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j02, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string j11 = "    XX    ";
    std::string j12 = "    X     ";
    std::string j13 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(j11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j13, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string j21 = "    X     ";
    std::string j22 = "    X     ";
    std::string j23 = "   XX     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(j21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j23, b)));
}

TEST_CASE("Piece rotate_kick basic rotation L", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::L);
    b.color(Shape::L);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string l01 = "   XXX    ";
    std::string l02 = "   X      ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l02, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string l11 = "    X     ";
    std::string l12 = "    X     ";
    std::string l13 = "    XX    ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(l11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l13, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string l21 = "   XX     ";
    std::string l22 = "    X     ";
    std::string l23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(l21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l23, b)));
}

TEST_CASE("Piece rotate_kick basic rotation T", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::T);
    b.color(Shape::T);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string t01 = "   XXX    ";
    std::string t02 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t02, b)));

    f.reset(10, 22);

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    std::string t11 = "    X     ";
    std::string t12 = "    XX    ";
    std::string t13 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(t11, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t12, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t13, b)));

    f.reset(10, 22);

    p.orientation_mut().reset();
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);
    std::string t21 = "    X     ";
    std::string t22 = "   XX     ";
    std::string t23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(1), 10), RangeEquals(to_vec(t21, b)));
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t22, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t23, b)));
}


TEST_CASE("Piece rotate_kick walls Z", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    b.color(Shape::Z);
    b.add_blink();
    p.spawn(Shape::Z);
    p.coordinates_mut().y++;

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string z01 = " X        ";
    std::string z02 = "XX        ";
    std::string z03 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(z03, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string z11 = "          ";
    std::string z12 = "XX        ";
    std::string z13 = " XX       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(z13, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Right);
    p.put(f);

    std::string z21 = " X        ";
    std::string z22 = "XX        ";
    std::string z23 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(z23, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string z31 = "          ";
    std::string z32 = "XX        ";
    std::string z33 = " XX       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(z31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(z32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(z33, b)));
    REQUIRE(p.coordinates().x == 0);
}

TEST_CASE("Piece rotate_kick walls S", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    b.color(Shape::S);
    b.add_blink();
    p.spawn(Shape::S);
    p.coordinates_mut().y++;

    f.reset(10, 22);
    p.coordinates_mut().x = 8;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string s01 = "        X ";
    std::string s02 = "        XX";
    std::string s03 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(s03, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string s11 = "          ";
    std::string s12 = "        XX";
    std::string s13 = "       XX ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(s13, b)));
    REQUIRE(p.coordinates().x == 7);

    f.reset(10, 22);
    p.coordinates_mut().x = 8;
    p.rotate(Rotation::Right);
    p.put(f);

    std::string s21 = "        X ";
    std::string s22 = "        XX";
    std::string s23 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(s23, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string s31 = "          ";
    std::string s32 = "        XX";
    std::string s33 = "       XX ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(s31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(s32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(s33, b)));
    REQUIRE(p.coordinates().x == 7);
}

TEST_CASE("Piece rotate_kick walls J", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    b.color(Shape::J);
    b.add_blink();
    p.spawn(Shape::J);
    p.coordinates_mut().y++;

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string j01 = "XX        ";
    std::string j02 = "X         ";
    std::string j03 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j03, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string j11 = "          ";
    std::string j12 = "X         ";
    std::string j13 = "XXX       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j13, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Left);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string j21 = "         X";
    std::string j22 = "         X";
    std::string j23 = "        XX";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j23, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string j31 = "          ";
    std::string j32 = "       XXX";
    std::string j33 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j33, b)));
    REQUIRE(p.coordinates().x == 7);

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string j41 = "XX        ";
    std::string j42 = "X         ";
    std::string j43 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j43, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j51 = "          ";
    std::string j52 = "XXX       ";
    std::string j53 = "  X       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j53, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Right);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string j61 = "         X";
    std::string j62 = "         X";
    std::string j63 = "        XX";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j61, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j62, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j63, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j71 = "          ";
    std::string j72 = "       X  ";
    std::string j73 = "       XXX";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j71, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j72, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j73, b)));
    REQUIRE(p.coordinates().x == 7);
}

TEST_CASE("Piece rotate_kick walls L", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    b.color(Shape::L);
    b.add_blink();
    p.spawn(Shape::L);
    p.coordinates_mut().y++;

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string l01 = "X         ";
    std::string l02 = "X         ";
    std::string l03 = "XX        ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l03, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string l11 = "          ";
    std::string l12 = "  X       ";
    std::string l13 = "XXX       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l13, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Left);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string l21 = "        XX";
    std::string l22 = "         X";
    std::string l23 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l23, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string l31 = "          ";
    std::string l32 = "       XXX";
    std::string l33 = "       X  ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l33, b)));
    REQUIRE(p.coordinates().x == 7);

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string l41 = "X         ";
    std::string l42 = "X         ";
    std::string l43 = "XX        ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l43, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l51 = "          ";
    std::string l52 = "XXX       ";
    std::string l53 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l53, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Right);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string l61 = "        XX";
    std::string l62 = "         X";
    std::string l63 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l61, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l62, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l63, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l71 = "          ";
    std::string l72 = "         X";
    std::string l73 = "       XXX";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l71, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l72, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l73, b)));
    REQUIRE(p.coordinates().x == 7);
}

TEST_CASE("Piece rotate_kick walls T", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    b.color(Shape::T);
    b.add_blink();
    p.spawn(Shape::T);
    p.coordinates_mut().y++;

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string t01 = "X         ";
    std::string t02 = "XX        ";
    std::string t03 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t03, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string t11 = "          ";
    std::string t12 = " X        ";
    std::string t13 = "XXX       ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t13, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Left);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string t21 = "         X";
    std::string t22 = "        XX";
    std::string t23 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t23, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);

    std::string t31 = "          ";
    std::string t32 = "       XXX";
    std::string t33 = "        X ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t33, b)));
    REQUIRE(p.coordinates().x == 7);

    f.reset(10, 22);
    p.coordinates_mut().x = -1;
    p.rotate(Rotation::Left);
    p.put(f);

    std::string t41 = "X         ";
    std::string t42 = "XX        ";
    std::string t43 = "X         ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t43, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string t51 = "          ";
    std::string t52 = "XXX       ";
    std::string t53 = " X        ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t53, b)));
    REQUIRE(p.coordinates().x == 0);

    f.reset(10, 22);
    p.rotate(Rotation::Right);
    p.coordinates_mut().x = 8;
    p.put(f);

    std::string t61 = "         X";
    std::string t62 = "        XX";
    std::string t63 = "         X";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t61, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t62, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t63, b)));

    f.reset(10, 22);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string t71 = "          ";
    std::string t72 = "        X ";
    std::string t73 = "       XXX";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t71, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t72, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t73, b)));
    REQUIRE(p.coordinates().x == 7);
}


TEST_CASE("Piece rotate_kick center column J", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::J);
    p.coordinates_mut().y++;
    b.color(Shape::J);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string j01 = "          ";
    std::string j02 = "   XXX    ";
    std::string j03 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j03, b)));

    f.reset(10, 22);

    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);
    p.put(f);
    std::string j11 = "          ";
    std::string j12 = "   X      ";
    std::string j13 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j13, b)));

    f.reset(10, 22);
    f.block_mut(4, 4) = b;
    p.orientation_mut().reset();

    std::string j21 = "          ";
    std::string j22 = "          ";
    std::string j23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j23, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j31 = "          ";
    std::string j32 = "   XXX    ";
    std::string j33 = "    XX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j33, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();

    std::string j41 = "    X     ";
    std::string j42 = "          ";
    std::string j43 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j43, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j51 = "    X     ";
    std::string j52 = "   XXX    ";
    std::string j53 = "     X    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j53, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();
    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);

    std::string j61 = "    X     ";
    std::string j62 = "          ";
    std::string j63 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j61, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j62, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j63, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j71 = "    X     ";
    std::string j72 = "   X      ";
    std::string j73 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j71, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j72, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j73, b)));

    f.reset(10, 22);
    f.block_mut(4, 3) = b;
    p.orientation_mut().reset();
    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);

    std::string j81 = "          ";
    std::string j82 = "    X     ";
    std::string j83 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j81, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j82, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j83, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string j91 = "          ";
    std::string j92 = "   XX     ";
    std::string j93 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(j91, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(j92, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(j93, b)));
}

TEST_CASE("Piece rotate_kick center column L", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::L);
    p.coordinates_mut().y++;
    b.color(Shape::L);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string l01 = "          ";
    std::string l02 = "   XXX    ";
    std::string l03 = "   X      ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l03, b)));

    f.reset(10, 22);

    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);
    p.put(f);
    std::string l11 = "          ";
    std::string l12 = "     X    ";
    std::string l13 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l13, b)));

    f.reset(10, 22);
    f.block_mut(4, 4) = b;
    p.orientation_mut().reset();

    std::string l21 = "          ";
    std::string l22 = "          ";
    std::string l23 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l23, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l31 = "          ";
    std::string l32 = "   XXX    ";
    std::string l33 = "   XX     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l33, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();

    std::string l41 = "    X     ";
    std::string l42 = "          ";
    std::string l43 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l43, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l51 = "    X     ";
    std::string l52 = "   XXX    ";
    std::string l53 = "   X      ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l53, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();
    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);

    std::string l61 = "    X     ";
    std::string l62 = "          ";
    std::string l63 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l61, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l62, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l63, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l71 = "    X     ";
    std::string l72 = "     X    ";
    std::string l73 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l71, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l72, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l73, b)));

    f.reset(10, 22);
    f.block_mut(4, 3) = b;
    p.orientation_mut().reset();
    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);

    std::string l81 = "          ";
    std::string l82 = "    X     ";
    std::string l83 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l81, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l82, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l83, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string l91 = "          ";
    std::string l92 = "    XX    ";
    std::string l93 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(l91, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(l92, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(l93, b)));
}

TEST_CASE("Piece rotate_kick center column T", "[piece]") {
    using Catch::Matchers::RangeEquals;

    Field f;
    Piece p;
    Block b;
    int ghost_y = 0;

    p.spawn(Shape::T);
    p.coordinates_mut().y++;
    b.color(Shape::T);
    b.add_blink();

    f.reset(10, 22);

    p.put(f);
    std::string t01 = "          ";
    std::string t02 = "   XXX    ";
    std::string t03 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t01, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t02, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t03, b)));

    f.reset(10, 22);

    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);
    p.put(f);
    std::string t11 = "          ";
    std::string t12 = "    X     ";
    std::string t13 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t11, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t12, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t13, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();

    std::string t21 = "    X     ";
    std::string t22 = "          ";
    std::string t23 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t21, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t22, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t23, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string t31 = "    X     ";
    std::string t32 = "   XXX    ";
    std::string t33 = "    X     ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t31, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t32, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t33, b)));

    f.reset(10, 22);
    f.block_mut(4, 2) = b;
    p.orientation_mut().reset();
    p.rotate(Rotation::Left);
    p.rotate(Rotation::Left);

    std::string t41 = "    X     ";
    std::string t42 = "          ";
    std::string t43 = "          ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t41, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t42, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t43, b)));

    p.rotate_kick(f, &ghost_y, Rotation::Left);
    p.put(f);
    p.rotate_kick(f, &ghost_y, Rotation::Right);
    p.put(f);

    std::string t51 = "    X     ";
    std::string t52 = "    X     ";
    std::string t53 = "   XXX    ";
    CHECK_THAT(to_vec(f.get_line(2), 10), RangeEquals(to_vec(t51, b)));
    CHECK_THAT(to_vec(f.get_line(3), 10), RangeEquals(to_vec(t52, b)));
    CHECK_THAT(to_vec(f.get_line(4), 10), RangeEquals(to_vec(t53, b)));
}
