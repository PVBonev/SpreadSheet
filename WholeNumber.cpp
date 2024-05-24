#include <iostream>
#include <string>
#include <vector>//for testing
#include "WholeNumber.h"

//WholeNumber::WholeNumber(int row, int column, int value) : Field(row, column, Type::WholeNum), value(value) {}

WholeNumber::WholeNumber(int row, int column, std::string value) : Field(row, column, value, Type::WholeNum){}

void WholeNumber::print() const 
{
    //Field::printO(
    std::cout<<"Printing whole number field\n";
    std::cout<<"Row: "<<getRow()<<" Column: "<<getCol()<<std::endl;
    std::cout << "The integer value + 10 is: " << std::stoi(value) + 10 << std::endl;
}
/*
int main()
{
    WholeNumber wn(1, 1, "123"),wn2(2, 2, "456");
    wn.print();
    wn2.print();
    std::vector<Field> fields;
    fields.push_back(wn);
    fields.push_back(wn2);

    std::cout<<"\nPrinting fields\n";
    for(std::size_t i = 0; i < fields.size(); ++i)
    {
        std::cout<<"Field: "<<i<<std::endl;
        fields[i].print();
        std::cout<<std::endl<<"value + 10 = "<<std::stoi(fields[i].getValue()) + 10<<std::endl<<std::endl;

        //fields[i].uselessFunc();
    }

    Field* fields2[2];
    fields2[0] = &wn;
    fields2[1] = &wn2;
    for(std::size_t i = 0; i < 2; ++i)
    {
        fields2[i]->print();
    }

    return 0;
}

*/