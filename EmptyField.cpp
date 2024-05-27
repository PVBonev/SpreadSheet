#include <iostream>
#include <string>
#include "EmptyField.h"

EmptyField::EmptyField(int row, int column)
    : Field(row, column, " ", Type::Empty) {}

std::string EmptyField::getValue() const
{
    return value;
}

void EmptyField::print() const
{
    //std::cout << "Printing empty field\n";
    std::cout<<"["<<getRow()<<"]["<<getCol()<<"] = "<<value<<'|'<<std::endl;

}
