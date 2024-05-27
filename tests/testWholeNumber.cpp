#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../WholeNumber.h"

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
}
