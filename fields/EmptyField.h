#pragma once
#include "Field.h"

/**
 * @class EmptyField
 * @brief A class representing an empty field in a spreadsheet.
 * @details This class inherits from the Field class.
 */
class EmptyField : public Field
{
public:
    /**
     * @brief Constructor for the EmptyField class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     */
    EmptyField(int row, int column);

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


EmptyField::EmptyField(int row, int column) 
    : Field(row, column, " ", Type::EMPTY) {}

Type EmptyField::getType() const
{
    return Type::EMPTY;
}

Field* EmptyField::clone() const
{
    return new EmptyField(*this);
}

