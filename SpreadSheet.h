#pragma once
#include <vector>
#include <string>
#include "./fields/Field.h"

class SpreadSheet
{
private:
    unsigned int rows;
    unsigned int cols;
    std::vector<std::vector<Field*>> fields;
    std::vector<int> colWidths;
    std::string fileN;    

    double calculateFormula(const std::string &formula) const;    

    void copy(const SpreadSheet& other);
    void erase();

public:
    SpreadSheet();
    SpreadSheet(const SpreadSheet& other);
    SpreadSheet& operator=(const SpreadSheet& other);
    ~SpreadSheet();

    void editField(int row, int col, std::string &value);
    void editField(int row, int col);
    void editField();
    void saveToFile(const std::string &fileName) const;
    void saveToFile() const;
    void loadFromFile(const std::string &fileName);
    void close();
    void print() const;

    void resize();

    void updateSpreadSheet();

    //NOT USED ANYWHERE
    //void addField(int row, int col,const Field* field);
    //void addField();

    
};