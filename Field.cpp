#include <iostream>
#include <string>
#include "Field.h"

Field::Field(int row, int column, std::string value, Type type) 
    : row(row), column(column), value(value), type(type) {}

std::string Field::getValueStr() const
{
    return value;
}

std::string Field::print() const
{
    //if(type == Type::StringField)
    //    return value.substr(1, value.size() - 2);
    return value;
}

double Field::getValue() const
{
    return 0;//by default
}

int Field::getLength() const
{
    return value.size();
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
    std::cout<<f.getValue()<<std::endl;

    return 0;
}
*/