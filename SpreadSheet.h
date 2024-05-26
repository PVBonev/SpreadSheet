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
    std::string fileName;

public:
    SpreadSheet();

    void addField(int row, int col, Field* field);
    void editField();
    void saveToFile(std::string fileName);
    void saveToFile();
    void loadFromFile(std::string fileName);
    void print() const;

    void tester();

};