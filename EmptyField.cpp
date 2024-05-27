#include <iostream>
#include <string>
#include "EmptyField.h"

EmptyField::EmptyField(int row, int column)
    : Field(row, column, " ", Type::Empty) {}

std::string EmptyField::getValueStr() const
{
    return value;
}

