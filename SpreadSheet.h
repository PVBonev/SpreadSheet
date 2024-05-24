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

public:
    SpreadSheet();

    void addField(int row, int col, Field* field);
    void editField(int row, int col);
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);
    void print() const;

};