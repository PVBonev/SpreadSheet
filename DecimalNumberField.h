#pragma once
#include <iostream>
#include "Field.h"

class DecimalNumberField : public Field
{
public:
    DecimalNumberField(int row, int column, std::string value);

    double getValue() const override;

    std::string print() const override;

    int getLength() const override;

    Type getType() const override;    
};

DecimalNumberField::DecimalNumberField(int row, int column, std::string value) : Field(row, column, value, Type::DecimalNumField){}

double DecimalNumberField::getValue() const
{
    return std::stod(value);
}

std::string DecimalNumberField::print() const
{
    if(value[0] == '.')
    {
        return "0" + value;
    }
    if(value[value.size()-1] == '.')
    {
        return value + "0";
    }
    return value;
}

int DecimalNumberField::getLength() const
{
    if(value[0] == '.' || value[value.size()-1] == '.')
    {
        return value.size() + 1;
    }
    return value.size();
}

Type DecimalNumberField::getType() const
{
    return Type::DecimalNumField;
}