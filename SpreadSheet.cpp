#include <iostream>
#include <cassert>
#include <string>//
#include "SpreadSheet.h"
#include "Field.h"
#include "WholeNumber.h"

int whatStringIsThat(std::string str)//returns 0 if its a whole number, 1 if its a decimal number, 2 if its a string
{
    //after execution only one of those flags will be true
    bool isWholeNumber = true;
    bool isDecimalNumber = true;
    bool isString = true;
    bool isFormula = true;
    //what do we do if we have an empty input? think later 

    //check if its a whole number
    for(std::size_t i = 0; i < str.size(); ++i)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            isWholeNumber = false;
            break;
        }
    }
    
    if(isWholeNumber)
    {
        return 1;
    }

    //check if its a decimal number
    if(str[str.size() - 1] == '.')// we consider a number that ends with a dot as invalid f e 12. is invalid
    {
        isDecimalNumber = false;
    }
    bool hasDot = false;
    for(std::size_t i = 0; i < str.size(); ++i)
    {
        

        if(str[i] == '.')//mark first occurance of a dot
        {
            if(hasDot == true)
            {
                isDecimalNumber = false;
                i = str.size();//break the loop
            }
            
            hasDot = true;
            continue;
        }

        if(str[i] < '0' || str[i] > '9' )
        {
            isDecimalNumber = false;
            i = str.size();//break the loop
        }        
    }

    if(isDecimalNumber)
    {
        return 2;
    }

    //check if its a string - string should start and end with "
    if(str[0] == '"' && str[str.size() - 1] == '"')
    {
        return 3;
    }

    //check if its a formula - formula should start with = and contain at least one operator
    //example valid formulas:
    //= 1 + 2
    //= R1C1 + R2C2
    int row1, col1, row2, col2;//assign the row and column values to these variables
    
    
    
    if(str[0] != '=' || false)//if the string starts with = and the rest is not a number
    {
        isFormula = false;
    }
    {
        isFormula = false;
    }
    bool hasOperator = false;
    for(std::size_t i = 0; i < str.size(); ++i)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if(hasOperator == true)
            {
                isFormula = false;
                i = str.size();//break the loop
            }
            hasOperator = true;
            continue;
        }
    }


    
    
    return 0;
}

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

        //we could also add emptyFields here as much as its needed

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

    std::cout<<"Enter the new value for the field: ";
    std::string newValue;
    getline(std::cin, newValue);

    int result = whatStringIsThat(newValue);
    switch (result)
    {
        case 0://0 is incorrect
        {    
            std::cout<<"Invalid input\n";
            break;
        }
        case 1://1 is whole number
        {
            Field* f = new WholeNumber(row, col, newValue);
            fields[row - 1][col - 1] = f;
            break;
        }
        case 2://2 is decimal number
        {
            //Field* f = new DecimalNum(row, col, newValue);//not yet implemented
            //fields[row - 1][col - 1] = f;
            break;
        }
        case 3://3 is string
        {
            //Field* f = new Text(row, col, newValue);//not yet implemented
            //fields[row - 1][col - 1] = f;
            break;
        }
        case 4://4 is formula
        {
            //Field* f = new Formula(row, col, newValue);//not yet implemented
            //fields[row - 1][col - 1] = f;
            break;
        }


    }
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

    //ss.editField(2, 3);
    //ss.editField(10, 10);
    ss.print();

    std::cout<<whatStringIsThat("123")<<std::endl;
    std::cout<<whatStringIsThat("0")<<std::endl;
    std::cout<<whatStringIsThat("1234567123")<<std::endl;
    std::cout<<whatStringIsThat("12s")<<std::endl;
    std::cout<<whatStringIsThat("a12")<<std::endl;
    std::cout<<whatStringIsThat("1a2")<<std::endl;
    std::cout<<std::endl;

    std::cout<<whatStringIsThat("12.3")<<std::endl;
    std::cout<<whatStringIsThat(".4")<<std::endl;
    std::cout<<whatStringIsThat("12.")<<std::endl;
    std::cout<<whatStringIsThat(".12.")<<std::endl;
    std::cout<<whatStringIsThat("12.3.4")<<std::endl;
    std::cout<<whatStringIsThat("12.3wasabi")<<std::endl;
    std::cout<<whatStringIsThat("was12.3")<<std::endl;
    std::cout<<whatStringIsThat("12was.3")<<std::endl;
    std::cout<<whatStringIsThat("12.was3")<<std::endl;
    std::cout<<std::endl;

    std::cout<<whatStringIsThat("\"12.3\"")<<std::endl;
    std::cout<<whatStringIsThat("\"text\"")<<std::endl;
    std::cout<<whatStringIsThat("\"12.3text\"")<<std::endl;
    std::cout<<whatStringIsThat("text\"12.3\"")<<std::endl;
    std::cout<<whatStringIsThat("\"12.3 text with space \"")<<std::endl;
    std::cout<<whatStringIsThat("\"12.3")<<std::endl;
    std::cout<<whatStringIsThat("12.3\"")<<std::endl;

    return 0;
}