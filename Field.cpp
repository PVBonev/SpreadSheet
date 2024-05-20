#include <iostream>
#include <string>
#include "Field.h"

Field::Field(int row, int column, std::string value, Type type) 
    : row(row), column(column), value(value), type(type) {}

void Field::print() const
{
    std::cout << "Row: " << row << " Column: " << column << " Type: " << type << std::endl;
    std::cout << "The value is: " << value << std::endl;
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

//for testing
/*
int main()
{
    Field f(1, 1, "123", Type::WholeNum), f2(2, 2, "456", Type::WholeNum);
    f.print();
    f2.print();

    return 0;
}
*/