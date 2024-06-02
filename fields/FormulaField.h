#pragma once
#include <string>
#include "Field.h"
#include "../Helpers.h"

class Formula : public Field
{
private:
    double result = 0;
public:
    Formula(int row, int column, std::string value,double result);

    std::string print() const override;

    void setResult(double result);

    int getLength() const override;

    Type getType() const override;

    double getValue() const override;

    Field* clone() const override;
};

Formula::Formula(int row, int column, std::string value,double result) : Field(row, column, value, Type::FormulaField), result(result) {}

std::string Formula::print() const
{
    return removeZeros(std::to_string(result));
}

void Formula::setResult(double result)
{
    this->result = result;
}

int Formula::getLength() const
{
    return print().size();
}

Type Formula::getType() const
{
    return Type::FormulaField;
}

double Formula::getValue() const
{
    return result;
}

Field* Formula::clone() const
{
    return new Formula(*this);
}