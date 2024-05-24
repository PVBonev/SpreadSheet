#include <iostream>
#include <cassert>
#include "SpreadSheet.h"
#include "Field.h"
#include "WholeNumber.h"

SpreadSheet::SpreadSheet()
{
    std::cout<<"SpreadSheet constructor\n";
    rows = 0;
    cols = 0;
}

//all good boss
void SpreadSheet::addField(int row, int col, Field* field)
{
    if(row > rows)//we are adding a a row thats new
    {
        
        rows = row;//update the table rows
        fields.resize(rows);//resize the rows
    }
    if(col > cols)//we are adding a new column
    {
        
        cols = col;//update the table columns
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            fields[i].resize(cols);//resize the columns
        }

    }
    
    fields[row - 1][col - 1] = field;

}

void SpreadSheet::editField(int row, int col)
{
    assert(row <= rows && "Row out of bounds");
    assert(col <= cols && "Column out of bounds");
}

void SpreadSheet::print() const
{
    for(std::size_t i = 0; i < fields.size(); ++i)
    {
        for(std::size_t j = 0; j < fields[i].size(); ++j)
        {
            if(fields[i][j] != nullptr)
            {
                fields[i][j]->print();
            }
        }
    }
}



int main()
{
    SpreadSheet ss;
    WholeNumber f(2, 3, "123"), f2(1, 2, "456"),f3(5, 5, "789");
    //std::vector<std::vector<Field>> fields;
    //fields.push_back({f});
    //fields.push_back({f2});
    //for(std::size_t i = 0; i < fields.size();++i)
    //{
    //    fields[i][0].print();
    //}

    ss.addField(2, 3, &f);
    ss.addField(1, 2, &f2);
    ss.addField(5, 5, &f3);

    ss.print();

    ss.editField(2, 3);
    ss.editField(10, 10);
    ss.print();
    return 0;
}