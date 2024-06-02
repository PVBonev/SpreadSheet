#pragma once
#include <string>
#include "Field.h"

class WholeNumber : public Field
{
public:
    WholeNumber(int row, int column, std::string value);

    double getValue() const override;

    Type getType() const override;

    Field* clone() const override;
};

WholeNumber::WholeNumber(int row, int column, std::string value) : Field(row, column, value, Type::WholeNumField){}

double WholeNumber::getValue() const
{
    return std::stoi(value);
}

Type WholeNumber::getType() const
{
    return Type::WholeNumField;
}

Field* WholeNumber::clone() const
{
    return new WholeNumber(*this);
}
