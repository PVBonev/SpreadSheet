#include <iostream>
#include "SpreadSheet.h"

SpreadSheet::SpreadSheet()
{
    rows = 0;
    cols = 0;
}

void SpreadSheet::addField(int row, int col, Field* field)
{
    if(row > rows)//if row is bigger than the current number of rows
    {//aka we want to add a non existing(till now) row
        rows = row;
        fields.resize(rows);
    }
    if(col > cols)
    {
        cols = col;
        for(int i = 0; i < rows; i++)
        {
            fields[i].resize(cols);
        }
    }
    fields[row][col].setValue() = field.getValue();
}