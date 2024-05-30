#pragma once
#include <vector>
#include <string>
#include "Field.h"

class SpreadSheet
{
private:
    unsigned int rows;
    unsigned int cols;
    std::vector<std::vector<Field*>> fields;
    std::vector<int> colWidths;
    std::string fileN;    

    double calculateFormula(std::string formula) const;//its private

    void updateSpreadSheet();//goes through the spreadSheet and updates the column widths and recalculates the formulas
    

public:
    SpreadSheet();

    void addField(int row, int col, Field* field);
    void editField();
    void saveToFile(std::string fileName) const;
    void saveToFile() const;
    void loadFromFile(std::string fileName);
    void close();
    void print() const;
};