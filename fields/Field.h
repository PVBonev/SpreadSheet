#pragma once
#include "Type.h"

/**
 * @class Field
 * @brief A class representing a field in a spreadsheet.
 */
class Field
{
private:
    int row; ///< The row of the field in the spreadsheet
    int column; ///< The column of the field in the spreadsheet
protected:
    std::string value; ///< The value of the field
    Type type; ///< The type of the field

public:
    /**
     * @brief Constructor for the Field class.
     * @param row The row of the field in the spreadsheet.
     * @param column The column of the field in the spreadsheet.
     * @param value The value of the field.
     * @param type The type of the field.
     */
    Field(int row, int column, std::string value, Type type);
    
    /**
     * @brief Gets the value of the field as a string.
     * @return The value of the field as a string.
     */
    virtual std::string getValueStr() const;

    /**
     * @brief Prints the field.
     * @return A string representation of the field.
     */
    virtual std::string print() const;

    /**
     * @brief Gets the value of the field as a double.
     * @return The value of the field as a double.
     */
    virtual double getValue() const;

    /**
     * @brief Gets the length of the field.
     * @return The length of the field.
     */
    virtual int getLength() const;

    /**
     * @brief Gets the type of the field.
     * @return The type of the field.
     */
    virtual Type getType() const =0;

    /**
     * @brief Clones the field.
     * @return A pointer to the cloned field.
     */
    virtual Field* clone() const =0;

    /**
     * @brief Destructor for the Field class.
     */
    virtual ~Field() {};

    //for the tests
    int getRow() const{ return row; }
    int getCol() const{ return column; }
};