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

public:
    SpreadSheet();

    void addField(int row, int col, Field* field);
    void editField(int row, int col, std::string value);
    void editField(int row, int col);
    void editField();
    void saveToFile(std::string fileName) const;
    void saveToFile() const;
    void loadFromFile(std::string fileName);
    void close();
    void print() const;

    void updateSpreadSheet();
};