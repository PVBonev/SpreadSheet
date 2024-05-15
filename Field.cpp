#include <iostream>
#include <string>
#include "Field.h"

Field Field::createWholeNumber(int row, int column)
{
    return Field(row, column, Type::WholeNumber);
}

Field Field::createDecimalNumber(int row, int column)
{
    return Field(row, column, Type::DecimalNumber);
}

Field Field::createText(int row, int column)
{
    return Field(row, column, Type::Text);
}

Field Field::createFormula(int row, int column)
{
    return Field(row, column, Type::Formula);
}

