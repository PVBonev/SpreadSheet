#pragma once
#include <string>
#include "Field.h"
#include "../Helpers.h"

/**
 * @class String
 * @brief A class representing a string field in a spreadsheet.
 * @details This class inherits from the Field class.
 */
class String : public Field
{
public:
    /**
     * @brief Constructor for the String class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     * @param value The value of the field.
     */
    String(int row, int column, std::string value);

    /**
     * @brief Prints the field.
     * @return A string representation of the field.
     */
    std::string print() const override;

    /**
     * @brief Gets the length of the field.
     * @return The length of the field.
     */
    int getLength() const override;

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

String::String(int row, int column, std::string value)
    : Field(row, column, value, Type::STRING){}

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
    return Type::STRING;
}

Field* String::clone() const
{
    return new String(*this);
}