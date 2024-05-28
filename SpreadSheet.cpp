#include <iostream>
#include <cassert>
#include <fstream>
#include "SpreadSheet.h"
#include "WholeNumberField.h"
#include "EmptyField.h"
#include "StringField.h"
#include "Helpers.h"


SpreadSheet::SpreadSheet()
{
    rows = 0;
    cols = 0;
    fileN = "";
    fields.resize(1);
    fields[0].resize(1);
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
    if(result != 0 && fields[row - 1][col - 1]->getLength() == colWidths[col - 1] && newValue.size() < colWidths[col - 1])
    {
        //if the new value is smaller than the current value and the current value is the longest in the column
        //then we need to update the column width
        colWidths[col - 1] = newValue.size();//in case our value is the new longest
        for(std::size_t i = 0; i < row; ++i)
        {
            if(fields[i][col - 1]->getLength() > newValue.size())
            {
                colWidths[col - 1] = fields[i][col - 1]->getLength();
                break;
            }
        }
        //we skip the row we are editing because there is the longest element for now
        for(std::size_t i = row; i < fields.size(); ++i)
        {
            if(fields[i][col - 1]->getLength() > newValue.size())
            {
                colWidths[col - 1] = fields[i][col - 1]->getLength();
                break;
            }
        }
    }

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
            if(colWidths[col - 1] < newValue.size())
            {
                colWidths[col - 1] = newValue.size();
            }
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
        case 5://5 is empty
        {
            Field* f = new EmptyField(row, col);
            fields[row - 1][col - 1] = f;
            break;
        }
    }
}

void SpreadSheet::print() const
{
    if(cols == 0 && rows == 0)
    {
        std::cout<<"Empty table\n";
        return;
    }
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
            std::cout<<fields[i][j]->getValueStr();
        }
        std::cout<<'|'<<std::endl;
    }
}

void SpreadSheet::saveToFile(std::string fileName)
{
    std::ofstream file(fileName, std::ios::trunc);
    if(file.is_open())
    {
        file<<rows<<'-'<<cols<<":\n";
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                file<<fields[i][j]->getValueStr()<<",";
            }
            file<<'\n';
        }
    }
    else
    {
        std::cout<<"Could not open the file\n";
    }
}

void SpreadSheet::saveToFile()
{
    if(fileN == "")
    {
        std::cout<<"Error: no file name\n";
    }
    else
    {
        saveToFile(fileN);
    }
}


void SpreadSheet::loadFromFile(std::string fileName)
{
    std::ifstream file(fileName);
    if(file.is_open())
    {
        std::string line;
        std::getline(file, line);
        std::size_t pos = line.find_first_of('-');
        std::size_t pos2 = line.find_first_of(':');
        rows = std::stoi(line.substr(0, pos));
        cols = std::stoi(line.substr(pos + 1, pos2 - pos - 1));
        fields.resize(rows);
        colWidths.resize(cols);
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            fields[i].resize(cols);
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                std::getline(file, line, ',');
                if (!file.eof() && file.peek() == '\n') // Check if the next character is a newline
                {
                    file.ignore(1); // Ignore the newline character
                }
                int resultType = whatStringIsThat(line);
                switch (resultType)
                {
                    case 0://0 is incorrect
                    {    
                        std::cout<<"Invalid input\n";
                        break;
                    }
                    case 1://1 is whole number
                    {
                        Field* f = new WholeNumber(i + 1, j + 1, line);
                        fields[i][j] = f;
                        break;
                    }
                    case 2://2 is decimal number
                    {
                        //Field* f = new DecimalNum(i + 1, j + 1, line);//not yet implemented
                        //fields[i][j] = f;
                        break;
                    }
                    case 3://3 is string
                    {
                        //Field* f = new Text(i + 1, j + 1, line);//not yet implemented
                        //fields[i][j] = f;
                        break;
                    }
                    case 4://4 is formula
                    {
                        //Field* f = new Formula(i + 1, j + 1, line);//not yet implemented
                        //fields[i][j] = f;
                        break;
                    }
                    case 5://5 is empty
                    {
                        Field* f = new EmptyField(i + 1, j + 1);
                        fields[i][j] = f;
                        break;
                    }
                }

                if(fields[i][j]->getLength() > colWidths[j])
                {
                    colWidths[j] = fields[i][j]->getLength();
                }
            }
            std::cout<<std::endl;
        }

        fileN = fileName;
    }
    else
    {
        std::cout<<"Could not open the file\n";
    }

    file.close();
}


void SpreadSheet::close()
{
    rows = 0;
    cols = 0;
    fields.clear();
    for(std::size_t i = 0; i < fields.size(); ++i)
    {
        fields[i].clear();
    }
    colWidths.clear();
    fileN = "";
}


/*
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
    

    SpreadSheet ss;
    WholeNumber f(1,1,"111"),f2(1,2,"22"),f3(1,3,"333");
    WholeNumber f4(2,1,"4"),f5(2,2,"5"),f6(2,3,"6");
    WholeNumber f7(3,1,"7"),f8(3,2,"8"),f9(3,3,"9");
    WholeNumber f10(5,1,"10"),f11(1,5,"11"),f12(5,5,"12");

    ss.addField(1, 1, &f);
    ss.addField(1, 2, &f2);
    ss.addField(1, 3, &f3);
    ss.addField(2, 1, &f4);
    ss.addField(2, 2, &f5);
    ss.addField(2, 3, &f6);
    ss.addField(3, 1, &f7);
    ss.addField(3, 2, &f8);
    ss.addField(3, 3, &f9);

    ss.addField(5, 1, &f10);
    ss.addField(1, 5, &f11);
    ss.addField(5,5, &f12);

    std::cout<<"Printing ss\n";
    ss.print();

    ss.editField();
    //ss.editField();
    ss.print();

    ss.saveToFile("test.txt");

    SpreadSheet ss2;
    ss2.loadFromFile("test.txt");
    std::cout<<"Printing ss2\n";
    ss2.print();
    ss2.saveToFile("test2.txt");

    std::cout<<"Printing ss updated\n";
    ss.loadFromFile("test2.txt");
    ss.print();
    
    return 0;
}

*/