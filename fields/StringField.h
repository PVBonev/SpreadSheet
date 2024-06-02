#pragma once
#include <string>
#include "Field.h"
#include "../Helpers.h"

class String : public Field
{
public:
    String(int row, int column, std::string value);

    std::string print() const override;

    int getLength() const override;

    double getValue() const override;

    Type getType() const override;

    Field* clone() const override;
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

double String::getValue() const
{
    if(isWholeNumber(value.substr(1, value.size() - 2)) || isDecimalNumber(value.substr(1, value.size() - 2)))
    {
        return std::stoi(value.substr(1, value.size() - 2));
    }else
    {
        return 0;
    }
}

Type String::getType() const
{
    return Type::StringField;
}

Field* String::clone() const
{
    return new String(*this);
}