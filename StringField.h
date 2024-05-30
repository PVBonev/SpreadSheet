#pragma once
#include <string>
#include "Field.h"

class String : public Field
{
public:
    String(int row, int column, std::string value);

    std::string print() const override;

    int getLength() const override;

    Type getType() const override;
};

String::String(int row, int column, std::string value)
    : Field(row, column, value, Type::StringField){}

std::string String::print() const//remove parenthesis
{
    return value.substr(1, value.size() - 2);
}

int String::getLength() const
{
    return value.size() - 2;
}

Type String::getType() const
{
    return Type::StringField;
}