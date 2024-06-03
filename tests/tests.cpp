#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../fields/WholeNumberField.h"
#include "../fields/EmptyField.h"
#include "../fields/StringField.h"
#include "../fields/DecimalNumberField.h"
#include "../fields/FormulaField.h"
#include "../Helpers.h"

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

TEST_CASE("Decimal number field")
{
    DecimalNumberField a(1,1,"5.5"),b(2,2,"5.54"),c(3,3,"15.6");
    REQUIRE(a.getValue() == 5.5);
    REQUIRE(b.getValue() == 5.5);
    REQUIRE(c.getValue() == 5.6);
    REQUIRE(a.getValue() != b.getValue());
    REQUIRE(a.getValue() != c.getValue());
    REQUIRE(a.getRow() == 1);
    REQUIRE(a.getCol() == 1);
    REQUIRE(b.getRow() == 2);
    REQUIRE(b.getCol() == 2);
    REQUIRE(c.getRow() == 3);
    REQUIRE(c.getCol() == 3);
    REQUIRE(a.getLength() == 3);
    REQUIRE(b.getLength() == 4);
    REQUIRE(c.getLength() == 4);
    REQUIRE(a.getType() == Type::DECIMAL_NUMBER);
    REQUIRE(b.getType() == Type::DECIMAL_NUMBER);
    REQUIRE(c.getType() == Type::DECIMAL_NUMBER);
}

TEST_CASE("Formula field")
{
    Formula a(1,1,"=5+5",10),b(2,2,"=R1C1+10",20),c(3,3,"=R1C1+R2C2",30),d(4,4,"=10+R1C1",40);
    REQUIRE(a.getValueStr() == "5+5");
    REQUIRE(b.getValueStr() == "R1C1+10");
    REQUIRE(c.getValueStr() == "R1C1+R2C2");
    REQUIRE(d.getValueStr() == "10+R1C1");
    REQUIRE(a.getValue() == 10);
    REQUIRE(b.getValue() == 20);
    REQUIRE(c.getValue() == 30);
    REQUIRE(d.getValue() == 40);
    REQUIRE(a.getType() == Type::FORMULA);
    REQUIRE(b.getType() == Type::FORMULA);
    REQUIRE(c.getType() == Type::FORMULA);
    REQUIRE(d.getType() == Type::FORMULA);
}
