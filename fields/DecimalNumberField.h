#pragma once
#include <iostream>
#include "Field.h"

class DecimalNumberField : public Field
{
public:
    DecimalNumberField(int row, int column, std::string value);

    double getValue() const override;

    Type getType() const override;   

    Field* clone() const override;
};

DecimalNumberField::DecimalNumberField(int row, int column, std::string value) : Field(row, column, value, Type::DecimalNumField){}

double DecimalNumberField::getValue() const
{
    return std::stod(value);
}

Type DecimalNumberField::getType() const
{
    return Type::DecimalNumField;
}

Field* DecimalNumberField::clone() const
{
    return new DecimalNumberField(*this);
}