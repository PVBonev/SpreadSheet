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
    Field();
    Field(int row, int column, std::string value, Type type);
    
    void setValue(std::string value);
    virtual std::string getValue() const;
    virtual int getTypeId() const { return (int)type; }

    //int getTypeId() const { return (int)type; }//this or maybe a more complicated version that checks the string and returns the type accordingly

    //for tests
    virtual void print() const;// = 0; perhaps

    int getRow() const { return row; }
    int getCol() const { return column; }
    int getLength() const { return value.size(); }
    
    /*//static Field createWholeNumber(int row, int column);

    //static Field createDecimalNumber(int row, int column);

    //static Field createText(int row, int column);

    //static Field createFormula(int row, int column);
    */
};
