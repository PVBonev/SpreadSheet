#pragma once
#include <iostream>
#include "Field.h"

/**
 * @class DecimalNumberField
 * @brief A class representing a decimal number field in a spreadsheet.
 * @details This class inherits from the Field class.
 */
class DecimalNumberField : public Field
{
public:
    /**
     * @brief Constructor for the DecimalNumberField class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     * @param value The value of the field.
     */
    DecimalNumberField(int row, int column, std::string value);

    /**
     * @brief Gets the value of the field as a double.
     * @return The value of the field as a double.
     */
    double getValue() const override;

    /**
     * @brief Gets the type of the field.
     * @return The type of the field.
     */
    Type getType() const override;   

    /**
     * @brief Clones the field.
     * @return A pointer to the cloned field.
     */
    Field* clone() const override;
};

DecimalNumberField::DecimalNumberField(int row, int column, std::string value) 
    : Field(row, column, value, Type::DECIMAL_NUMBER){}

double DecimalNumberField::getValue() const
{
    return std::stod(value);
}

Type DecimalNumberField::getType() const
{
    return Type::DECIMAL_NUMBER;
}

Field* DecimalNumberField::clone() const
{
    return new DecimalNumberField(*this);
}