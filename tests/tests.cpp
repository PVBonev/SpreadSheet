#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../WholeNumberField.h"
#include "../EmptyField.h"
#include "../StringField.h"

TEST_CASE("WholeNumber")
{
    WholeNumber a(1,1,"5");
    REQUIRE(a.getValue() == 5);
    REQUIRE(a.getRow() == 1);
    REQUIRE(a.getCol() == 1);
    WholeNumber b(2,2,"5");
    REQUIRE(a.getValue() == b.getValue());
    REQUIRE(b.getRow() == 2);
    REQUIRE(b.getCol() == 2);
    WholeNumber c(3,3,"6");
    REQUIRE(a.getValue() != c.getValue());
    WholeNumber d(4,4,"123"),e(5,5,"1234567"),f(6,6,"123456789");
    REQUIRE(d.getLength() == 3);
    REQUIRE(e.getLength() == 7);
    REQUIRE(f.getLength() == 9);
    REQUIRE(d.getValue() == 123);
    REQUIRE(e.getValue() == 1234567);
    REQUIRE(f.getValue() == 123456789);
}

TEST_CASE("Empty Field")
{
    EmptyField a(1,10),b(2,20),c(3,30);
    REQUIRE(a.getRow() == 1);
    REQUIRE(a.getCol() == 10);
    REQUIRE(a.getValueStr() == " ");
    REQUIRE(b.getRow() == 2);
    REQUIRE(b.getCol() == 20);
    REQUIRE(b.getValueStr() == " ");
    REQUIRE(c.getRow() == 3);
    REQUIRE(c.getCol() == 30);
    REQUIRE(c.getValueStr() == " ");
}

TEST_CASE("String Field")
{
    String a(1,1,"\"hello\""),b(2,2,"\"world\""),c(3,3,"\"hello\"");
    REQUIRE(a.getRow() == 1);
    REQUIRE(a.getCol() == 1);
    REQUIRE(a.getValueStr() == "hello");
    REQUIRE(b.getRow() == 2);
    REQUIRE(b.getCol() == 2);
    REQUIRE(b.getValueStr() == "world");
    REQUIRE(c.getRow() == 3);
    REQUIRE(c.getCol() == 3);
    REQUIRE(c.getValueStr() == "hello");
    REQUIRE(a.getValueStr() == c.getValueStr());
    REQUIRE(a.getValueStr() != b.getValueStr());
    REQUIRE(a.getValue() == 0);
    REQUIRE(b.getValue() == 0);
    REQUIRE(c.getValue() == 0);
}
