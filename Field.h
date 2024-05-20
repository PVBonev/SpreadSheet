#pragma once
#include "Type.h"

class Field
{
private:
    int row;
    int column;
    std::string value;//maybe we can do that for easier spreadsheet class use
    Type type;

    

public:
    Field(int row, int column, std::string value, Type type);

    virtual bool isValid() = 0;
    //virtual void setValue(std::string value) = 0;
    //virtual std::string getValue() const = 0;

    //int getTypeId() const { return (int)type; }//this or maybe a more complicated version that checks the string and returns the type accordingly

    //for tests
    virtual void print() const;

    int getRow() const { return row; }
    int getCol() const { return column; }
    
    /*//static Field createWholeNumber(int row, int column);

    //static Field createDecimalNumber(int row, int column);

    //static Field createText(int row, int column);

    //static Field createFormula(int row, int column);
    */
};
