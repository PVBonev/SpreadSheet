#include <iostream>
#include <string>
#include "WholeNumber.h"

//WholeNumber::WholeNumber(int row, int column, int value) : Field(row, column, Type::WholeNum), value(value) {}

WholeNumber::WholeNumber(int row, int column, std::string value) : Field(row, column, value, Type::WholeNum),intValue(std::stoi(value)) {}

void WholeNumber::print() const 
{
    //Field::printO(
    std::cout<<"Row: "<<getRow()<<" Column: "<<getCol()<<std::endl;
    std::cout << "The integer value is: " << intValue << std::endl;
}

/*
void WholeNumber::setValue(int value)
{
    this->value = value;
}

void WholeNumber::setValue(std::string value)
{
    this->value = std::stoi(value);
}


*/
bool WholeNumber::isValid()//change when implemented
{
    throw std::logic_error("The method or operation is not implemented.");
}


int main()
{
    WholeNumber wn(1, 1, "123"),wn2(2, 2, "456");
    wn.print();
    wn2.print();

    return 0;
}