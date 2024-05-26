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
    std::cout << "Printing empty field\n";
    std::cout << "Row: " << getRow() << " Column: " << getCol() << " Type: " << type << std::endl;
    std::cout << "The value is: " << value << std::endl;
}
