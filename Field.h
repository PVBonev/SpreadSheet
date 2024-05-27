#pragma once
#include "Type.h"

class Field
{
private:
    int row;
    int column;
protected:
    std::string value;//maybe we can do that for easier spreadsheet class use
    Type type;
    //maybe new type for empty cell and by default we set all Fields to empty cell
    //new class empty cell?

    //bool isValid(std::string value) const;

    

public:
    Field(int row, int column, std::string value, Type type);
    
    virtual std::string getValueStr() const;

    //int getTypeId() const { return (int)type; }//this or maybe a more complicated version that checks the string and returns the type accordingly

    //for tests
    void print() const; //perhaps

    int getRow() const { return row; }
    int getCol() const { return column; }
    int getLength() const { return value.size(); }
    
    /*//static Field createWholeNumber(int row, int column);

    //static Field createDecimalNumber(int row, int column);

    //static Field createText(int row, int column);

    //static Field createFormula(int row, int column);
    */
};
