#include <iostream>
#include <string>
#include "Field.h"

Field::Field(int row, int column, Type type) : row(row), column(column), type(type) {}

void Field::printO() const
{
    std::cout << "Row: " << row << " Column: " << column << " Type: " << type << std::endl;
}

/*

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

*/


