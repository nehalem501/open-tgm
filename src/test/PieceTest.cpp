/* PieceTest.cpp */

#include <Piece.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_range_equals.hpp>

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

static std::vector<uint16_t> to_vec(const Block* data, size_t length) {
    std::vector<uint16_t> v;
    for (size_t i = 0; i < length; i++) {
        v.push_back(data[i].raw());
    }
    return v;
}

static std::vector<uint16_t> to_vec(std::string str, Block value) {
    std::vector<uint16_t> v;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            v.push_back(0);
        } else {
            v.push_back(value.raw());
        }
    }
    return v;
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