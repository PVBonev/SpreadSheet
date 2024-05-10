#pragma once
#include "Type.h"

class Field
{
private:
    int row;
    int column;
    Type type;

    Field(int row, int column, Type type) : row(row), column(column), type(type) {}

public:
    static Field createWholeNumber(int row, int column);

    static Field createDecimalNumber(int row, int column);

    static Field createText(int row, int column);

    static Field createFormula(int row, int column);
};
