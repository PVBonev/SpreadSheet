#include <iostream>
#include <cassert>
#include <fstream>
#include "SpreadSheet.h"
#include "Field.h"
#include "WholeNumber.h"
#include "EmptyField.h"

//all good
bool isWholeNumber(std::string str)
{
    for(std::size_t i = 0; i < str.size(); ++i)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}
//all good
bool isDecimalNumber(std::string str)
{
    bool hasDot = false;
    for(std::size_t i = 0; i < str.size(); ++i)
    {
        if(str[i] == '.')
        {
            if(hasDot == true)
            {
                return false;
            }
            hasDot = true;
            continue;
        }
        if(str[i] < '0' || str[i] > '9')
        {
            return false;
        }
    }
    return true;
}
//all good
bool isString(std::string str)
{
    if(str[0] == '"' && str[str.size() - 1] == '"')
    {
        return true;
    }
    return false;
}

//weak and obsolete
//only works for R1C1 format(1 digit row and 1 digit column)
bool isAdress(std::string str)
{
    if(str[0] == 'R' && str[2] == 'C' && str[1] >= '0' && str[1] <= '9' && str[3] >= '0' && str[3] <= '9')
    {
        return true;
    }
    return false;

}

//all good boss
bool isAdress2(std::string str)
{
    
    if(str[0] == 'R' && str.size() >=4)
    {
        std::size_t pos = str.find_first_of('C');

        if(pos != std::string::npos)
        {
            std::string row = str.substr(1, pos - 1);//the actual number part
            std::string col = str.substr(pos + 1);//the actual number part

            std::cout<<"substrings 1 and 2:"<<row<<" "<<col<<std::endl;


            if(isWholeNumber(row) && isWholeNumber(col))
            {
                if(std::stoi(row) > 0 && std::stoi(col) > 0
                  && std::stoi(row) < 100 && std::stoi(col) < 100)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isFormula(const std::string& str) 
{
  if (str[0] == '=') 
  {
    // Find the first occurrence of any operator (+, -, *, /)
    size_t pos = str.find_first_of("+-*/");

    // Check if an operator was found
    if (pos != std::string::npos) 
    {
        // Extract substrings
        std::string substr1 = str.substr(1, pos - 1); 
        std::string substr2 = str.substr(pos + 1);

        if((isWholeNumber(substr1) || isAdress2(substr1)) && (isWholeNumber(substr2) || isAdress2(substr2)))
        return true;
    }
  }

  return false;
}

//all good
//returns 0 if its a whole number, 1 if its a decimal number, 2 if its a string
int whatStringIsThat(std::string str)
{
    if(isWholeNumber(str))
    {
        return 1;
    }
    if(isDecimalNumber(str))
    {
        return 2;
    }
    if(isString(str))
    {
        return 3;
    }
    if(isFormula(str))
    {
        return 4;
    }   
    
    return 0;
}

SpreadSheet::SpreadSheet()
{
    rows = 0;
    cols = 0;
    fileName = "";
}

//now we good
void SpreadSheet::addField(int row, int col, Field* field)
{
    if(row > rows)//we are adding a a row thats new
    {
        fields.resize(row);//resize the rows
        
        for(std::size_t i = rows; i < fields.size(); ++i)
        {
            fields[i].resize(cols);//resize the columns
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                if(fields[i][j] == nullptr)
                fields[i][j] = new EmptyField(i + 1, j + 1);//add empty fields
            }
        }
        rows = row;//update the table rows
    }
    if(col > cols)//we are adding a new column
    {
        cols = col;//update the table columns
        colWidths.resize(cols);//resize the columns
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            fields[i].resize(cols);//resize the columns
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                if(fields[i][j] == nullptr)
                fields[i][j] = new EmptyField(i + 1, j + 1);//add empty fields
            }
        }

    }

    fields[row - 1][col - 1] = field;
    
    if(field->getLength() > colWidths[col - 1])
    {
        colWidths[col - 1] = field->getLength();
    }    
}

void SpreadSheet::editField()
{
    int row, col;
    do{
        std::cout<<"Enter row: ";
        std::cin>>row;
        std::cout<<"Enter column: ";
        std::cin>>col;
    }while(row > rows || col > cols);
    std::cout<<"Enter the new value for the field: ";
    std::string newValue;
    std::cin.ignore();
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

    //!!!IMPORTANT!!!
    //problem is that if we change the value of the field with the longest current length 
    //to a field with a smaller length then the column width will not be updated
    if(colWidths[col - 1] < newValue.size())
    {
        colWidths[col - 1] = newValue.size();
    }
}

void SpreadSheet::print() const
{
    std::cout<<"Printing the table\n";
    std::cout<<"Rows: "<<fields.size()<<" Cols: "<<fields[0].size()<<"\n";
    for(std::size_t i = 0; i < fields.size(); ++i)
    {
        
        for(std::size_t j = 0; j < fields[i].size(); ++j)
        {
            std::cout<<"| ";
                int numOfSpaces = colWidths[j] - fields[i][j]->getLength();
                for(int k = 0; k < numOfSpaces; ++k)
                {
                    std::cout<<' ';
                }
                std::cout<<fields[i][j]->getValue();
        }
        std::cout<<'|'<<std::endl;
    }
}

void SpreadSheet::saveToFile(std::string fileName)
{
    //format will be
    //rows cols: fields[0][0]->getValue() fields[0][1]->getValue() ... fields[0][cols - 1]->getValue()
    //fields[1][0]->getValue() fields[1][1]->getValue() ... fields[1][cols - 1]->getValue()
    //...
    //fields[rows - 1][0]->getValue() fields[rows - 1][1]->getValue() ... fields[rows - 1][cols - 1]->getValue()

    //override previous content in file
    std::ofstream file(fileName, std::ios::trunc);
    if(file.is_open())
    {
        file<<rows<<' '<<cols<<": ";
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                file<<fields[i][j]->getValue()<<", ";
            }
            file<<'\n';
        }
    }
    else
    {
        std::cout<<"Could not open the file\n";
    }
}


int main()
{
    /*

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
    
    std::cout<<std::boolalpha<<isAdress2("R1C1")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1C2")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R8C4")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1C12")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R10C1")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1CD")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1C")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1C2D")<<std::endl;
    std::cout<<std::boolalpha<<isAdress2("R1c2")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=1*0")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=1+2")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=R1C1+5")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=R1C1+R2C2")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=4+R3C3")<<std::endl;
    //std::cout<<std::boolalpha<<isFormula("=R1C1+R2C2")<<std::endl;
    */

    SpreadSheet ss;
    WholeNumber f(1,1,"111"),f2(1,2,"22"),f3(1,3,"333");
    WholeNumber f4(2,1,"4"),f5(2,2,"5"),f6(2,3,"6");
    WholeNumber f7(3,1,"7"),f8(3,2,"8"),f9(3,3,"9");
    WholeNumber f10(10,1,"10"),f11(1,12,"11"),f12(11,15,"12");

    ss.addField(1, 1, &f);
    ss.addField(1, 2, &f2);
    ss.addField(1, 3, &f3);
    ss.addField(2, 1, &f4);
    ss.addField(2, 2, &f5);
    ss.addField(2, 3, &f6);
    ss.addField(3, 1, &f7);
    ss.addField(3, 2, &f8);
    ss.addField(3, 3, &f9);

    ss.addField(10, 1, &f10);
    ss.addField(1, 12, &f11);
    ss.addField(11,15, &f12);

    ss.print();

    //ss.editField();
    //ss.editField();
    //ss.print();

    ss.saveToFile("test.txt");
    return 0;
}