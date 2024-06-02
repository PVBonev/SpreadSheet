#define CATCH_CONFIG_MAIN
#include "catch2.hpp"
#include "../Helpers.h"

TEST_CASE("Is whole number")
{
    REQUIRE(isWholeNumber("5") == true);
    REQUIRE(isWholeNumber("54") == true);
    REQUIRE(isWholeNumber("123456789") == true);
    REQUIRE(isWholeNumber("5.5") == false);
    REQUIRE(isWholeNumber("5.5.5") == false);
    REQUIRE(isWholeNumber("text") == false);
    REQUIRE(isWholeNumber("text5") == false);
    REQUIRE(isWholeNumber("5text") == false);    
}

TEST_CASE("Is empty")
{
    REQUIRE(isEmpty(" ") == true);
    REQUIRE(isEmpty("  ") == false);
    REQUIRE(isEmpty("text") == false);
    REQUIRE(isEmpty("5") == false);
    REQUIRE(isEmpty("5.5") == false);
    REQUIRE(isEmpty("5.5.5") == false);
    REQUIRE(isEmpty("text5") == false);
    REQUIRE(isEmpty("5text") == false);
}

TEST_CASE("Is decimal number")
{
    REQUIRE(isDecimalNumber("5.5") == true);
    REQUIRE(isDecimalNumber("12.34") == true);
    REQUIRE(isDecimalNumber("12.") == true);
    REQUIRE(isDecimalNumber(".12") == true);
    REQUIRE(isDecimalNumber("5.text") == false);
    REQUIRE(isDecimalNumber("text.5") == false);
    REQUIRE(isDecimalNumber("5.5.5") == false);
    REQUIRE(isDecimalNumber("text") == false);
    REQUIRE(isDecimalNumber("text5") == false);
    REQUIRE(isDecimalNumber("5text") == false);
}

TEST_CASE("Is string")
{
    REQUIRE(isString("\"text\"") == true);
    REQUIRE(isString("\"text5\"") == true);
    REQUIRE(isString("\"5text\"") == true);
    REQUIRE(isString("\"5\"") == true);
    REQUIRE(isString("\"str") == false);
    REQUIRE(isString("str\"") == false);
    REQUIRE(isString("54") == false);
    REQUIRE(isString("5.5") == false);
    REQUIRE(isString("5.5.5") == false);
    REQUIRE(isString(" ") == false);
    REQUIRE(isString("  ") == false);
}

TEST_CASE("Is adress")
{
    REQUIRE(isAdress2("R1C1") == true);
    REQUIRE(isAdress2("R1C2") == true);
    REQUIRE(isAdress2("R20C1") == true);
    REQUIRE(isAdress2("R1C20") == true);
    REQUIRE(isAdress2("R20C20") == true);
    REQUIRE(isAdress2("R1C") == false);
    REQUIRE(isAdress2("R1") == false);
    REQUIRE(isAdress2("C1") == false);
    REQUIRE(isAdress2("R") == false);
    REQUIRE(isAdress2("C") == false);
    REQUIRE(isAdress2("R1C1C1") == false);
}

TEST_CASE("Is formula")
{
    REQUIRE(isFormula("=5+5") == true);
    REQUIRE(isFormula("=5-5") == true);
    REQUIRE(isFormula("=5*5") == true);
    REQUIRE(isFormula("=5/5") == true);
    REQUIRE(isFormula("=R1C1+2") == true);
    REQUIRE(isFormula("=1+R1C1") == true);
    REQUIRE(isFormula("=R1C1+R1C1") == true);
    REQUIRE(isFormula("=5+5+5") == false);
    REQUIRE(isFormula("=RC+2") == false);
    REQUIRE(isFormula("=R1C1+text") == false);
    REQUIRE(isFormula("=text+R1C1") == false);
    REQUIRE(isFormula("=R1C1+R1C1+R1C1") == false);
    
}
