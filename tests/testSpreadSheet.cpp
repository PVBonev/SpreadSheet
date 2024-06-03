#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../SpreadSheet.h"

TEST_CASE("SpreadSheet")
{
    SpreadSheet a;
    REQUIRE(a.getRows() == 0);
    REQUIRE(a.getCols() == 0);
    REQUIRE(a.getFileName() == "");
    REQUIRE(a.getFields().size() == 1);
    a.loadFromFile("test.txt");
    REQUIRE(a.getRows() == 7);
    REQUIRE(a.getCols() == 7);
    REQUIRE(a.getFileName() == "test.txt");
    REQUIRE(a.getFields().size() == 7);

}