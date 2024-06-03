#pragma once
#include <string>
#include "Field.h"
#include "../Helpers.h"

/**
 * @class Formula
 * @brief A class representing a formula field in a spreadsheet.
 * @details This class inherits from the Field class.
 */
class Formula : public Field
{
private:
    double result = 0; ///< The result of the formula

public:
    /**
     * @brief Constructor for the Formula class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     * @param value The value of the field.
     * @param result The result of the formula.
     */
    Formula(int row, int column, std::string value,double result);

    /**
     * @brief Prints the field.
     * @return A string representation of the field.
     */
    std::string print() const override;

    /**
     * @brief Sets the result of the formula.
     * @param result The result of the formula.
     */
    void setResult(double result);

    /**
     * @brief Gets the length of the field.
     * @return The length of the field.
     */
    int getLength() const override;

    /**
     * @brief Gets the type of the field.
     * @return The type of the field.
     */
    Type getType() const override;

    /**
     * @brief Gets the value of the field as a double.
     * @return The value of the field as a double.
     */
    double getValue() const override;

    /**
     * @brief Clones the field.
     * @return A pointer to the cloned field.
     */
    Field* clone() const override;
};


Formula::Formula(int row, int column, std::string value,double result) 
    : Field(row, column, value, Type::FORMULA), result(result) {}

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
    return Type::FORMULA;
}

double Formula::getValue() const
{
    return result;
}

Field* Formula::clone() const
{
    return new Formula(*this);
}