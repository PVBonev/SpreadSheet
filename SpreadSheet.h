#pragma once
#include <vector>
#include <string>
#include "./fields/Field.h"

/**
 * @class SpreadSheet
 * @brief A class representing a spreadsheet.
 */
class SpreadSheet
{
private:
    unsigned int rows; ///< Number of rows in the spreadsheet
    unsigned int cols; ///< Number of columns in the spreadsheet
    std::vector<std::vector<Field*>> fields; ///< 2D vector representing the fields in the spreadsheet
    std::vector<int> colWidths; ///< Vector storing the widths of the columns
    std::string fileN; ///< Name of the file associated with the spreadsheet

    /**
     * @brief Calculates the result of a formula.
     * @param formula The formula to calculate.
     * @return The result of the calculation.
     */
    double calculateFormula(const std::string &formula) const;    

    /**
     * @brief Copies the data from another spreadsheet.
     * @param other The spreadsheet to copy from.
     */
    void copy(const SpreadSheet& other);

    /**
     * @brief Erases the data in the spreadsheet.
     */
    void erase();

public:
    /**
     * @brief Default constructor for the spreadsheet.
     */
    SpreadSheet();

    /**
     * @brief Copy constructor for the spreadsheet.
     * @param other The spreadsheet to copy from.
     */
    SpreadSheet(const SpreadSheet& other);

    /**
     * @brief Assignment operator for the spreadsheet.
     * @param other The spreadsheet to assign from.
     * @return A reference to the assigned spreadsheet.
     */
    SpreadSheet& operator=(const SpreadSheet& other);

    /**
     * @brief Destructor for the spreadsheet.
     */
    ~SpreadSheet();

    /**
     * @brief Edits a field in the spreadsheet.
     * @param row The row of the field.
     * @param col The column of the field.
     * @param value The new value for the field.
     */
    void editField(int row, int col, std::string &value);

    /**
     * @brief Edits a field in the spreadsheet.
     * @param row The row of the field.
     * @param col The column of the field.
     */
    void editField(int row, int col);

    /**
     * @brief Edits a field in the spreadsheet.
     */
    void editField();

    /**
     * @brief Saves the spreadsheet to a file.
     * @param fileName The name of the file to save to.
     */
    void saveToFile(const std::string &fileName) const;

    /**
     * @brief Saves the spreadsheet to a file.
     */
    void saveToFile() const;

    /**
     * @brief Loads the spreadsheet from a file.
     * @param fileName The name of the file to load from.
     */
    void loadFromFile(const std::string &fileName);

    /**
     * @brief Closes the spreadsheet.
     */
    void close();

    /**
     * @brief Prints the spreadsheet.
     */
    void print() const;

    /**
     * @brief Resizes the spreadsheet.
     */
    void resize();

    /**
     * @brief Updates the spreadsheet.
     */
    void updateSpreadSheet();


    //for the tests
    unsigned getRows() const{ return rows; }
    unsigned getCols() const{ return cols; }
    std::string getFileName() const{ return fileN; }
    std::vector<std::vector<Field*>> getFields() const{ return fields; }
};
