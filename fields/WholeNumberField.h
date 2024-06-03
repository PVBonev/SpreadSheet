#pragma once
#include <string>
#include "Field.h"

/**
 * @class WholeNumber
 * @brief A class representing a whole number field in a spreadsheet.
 * @details This class inherits from the Field class.
 */
class WholeNumber : public Field
{
public:
    /**
     * @brief Constructor for the WholeNumber class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     * @param value The value of the field.
     */
    WholeNumber(int row, int column, std::string value);

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

WholeNumber::WholeNumber(int row, int column, std::string value) 
    : Field(row, column, value, Type::WHOLE_NUMBER){}

double WholeNumber::getValue() const
{
    return std::stoi(value);
}

Type WholeNumber::getType() const
{
    return Type::WHOLE_NUMBER;
}

Field* WholeNumber::clone() const
{
    return new WholeNumber(*this);
}
