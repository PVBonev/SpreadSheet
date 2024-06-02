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

public:
    Field(int row, int column, std::string value, Type type);
    
    virtual std::string getValueStr() const;
    virtual std::string print() const;
    virtual double getValue() const;

    virtual int getLength() const;

    virtual Type getType() const =0;

    virtual Field* clone() const =0;

    virtual ~Field() {};
};
