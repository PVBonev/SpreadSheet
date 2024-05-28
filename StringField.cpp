#include "StringField.h"

StringField::StringField(int row, int column, std::string value)
    : Field(row, column, value, Type::String){}

int StringField::getValue() const
{
    return 0;
}