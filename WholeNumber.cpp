#include <iostream>
#include <string>
#include "WholeNumber.h"

WholeNumber::WholeNumber(int row, int column, int value) : Field(row, column, Type::WholeNum), value(value) {}

WholeNumber::WholeNumber(int row, int column, std::string value) : Field(row, column, Type::WholeNum), value(std::stoi(value)) {}

void WholeNumber::setValue(int value)
{
    this->value = value;
}

void WholeNumber::setValue(std::string value)
{
    this->value = std::stoi(value);
}

int WholeNumber::getValue() const
{
    return value;
}

bool WholeNumber::isValid()
{
    return true;
}

void WholeNumber::print() const
{
    //Field::printO();//why doesn't it work?
    std::cout<<"Row: "<<getRow()<<" Column: "<<getColumn()<<" Type: "<<Type::WholeNum;
    std::cout <<"The value is: "<< value << std::endl;
}

int main()
{
    WholeNumber wn(1, 2, 30001);
    wn.print();
    WholeNumber wn2(1, 2, "362317323");
    wn2.print();
    return 0;
}