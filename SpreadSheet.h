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

public:
    SpreadSheet();

    void addField(int row, int col, Field* field);
    void editField();
    void saveToFile(std::string fileName);
    void saveToFile();
    void loadFromFile(std::string fileName);
    void close();
    void print() const;
};