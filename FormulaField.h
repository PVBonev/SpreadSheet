#pragma once
#include <string>
#include "Field.h"
#include "Helpers.h"

class Formula : public Field
{
private:
    double result = 0;
public:
    Formula(int row, int column, std::string value);

    std::string print() const override;

    void setResult(double result);

    int getLength() const override;

    Type getType() const override;

    //double getValue() const override;
};

Formula::Formula(int row, int column, std::string value) : Field(row, column, value, Type::FormulaField)
{
    std::cout<<"Row: "<<row<<" Column: "<<column<<" Value: "<<value<<" Result: "<<result<<std::endl;
}

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

//double Formula::getValue() const
//{
//    return result;
//}