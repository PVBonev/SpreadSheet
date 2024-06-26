#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>//for std::pow
#include <algorithm>//for std::count
#include "SpreadSheet.h"
#include "./fields/WholeNumberField.h"
#include "./fields/EmptyField.h"
#include "./fields/StringField.h"
#include "./fields/FormulaField.h"
#include "./fields/DecimalNumberField.h"
#include "Helpers.h"


void SpreadSheet::copy(const SpreadSheet& other)
{
    rows = other.rows;
    cols = other.cols;
    for(std::size_t i = 0; i < other.fields.size(); ++i)
    {
        for(std::size_t j = 0; j < other.fields[i].size(); ++j)
        {
            fields[i][j] = other.fields[i][j]->clone();
        }
    }
    colWidths = other.colWidths;
    fileN = other.fileN;
} 

void SpreadSheet::erase()
{
    for(std::size_t i = 0; i < fields.size(); ++i)
    {
        for(std::size_t j = 0; j < fields[i].size(); ++j)
        {
            delete fields[i][j];
        }
    }
}

SpreadSheet::SpreadSheet()
{
    rows = 0;
    cols = 0;
    fileN = "";
    fields.resize(1);
    fields[0].resize(1);
}

SpreadSheet::SpreadSheet(const SpreadSheet& other)
{
    copy(other);
}

SpreadSheet& SpreadSheet::operator=(const SpreadSheet& other)
{
    if(this != &other)
    {
        erase();
        copy(other);
    }
    return *this;
}

SpreadSheet::~SpreadSheet()
{
    erase();
}

double SpreadSheet::calculateFormula(const std::string &formula) const
{
    double val1 = 0,val2 = 0;

    std::size_t pos = formula.find_first_of("+-*^/");

    if(pos == std::string::npos)
    {
        std::cerr<<"Error: invalid operator\n";
    }
    
    std::string first = formula.substr(1, pos - 1);
    std::string second = formula.substr(pos + 1, formula.size() - pos - 1);

    if(isWholeNumber(first) || isDecimalNumber(first))
    {
        val1 = std::stod(first);
    }
    if(isAdress2(first))
    {
        std::size_t pos = first.find_first_of('C');
        int row = std::stoi(first.substr(1, pos - 1));
        int col = std::stoi(first.substr(pos + 1));
        val1 = fields[row - 1][col - 1]->getValue();

    }
    if(isWholeNumber(second) || isDecimalNumber(second))
    {
        val2 = std::stod(second);
    }
    if(isAdress2(second))
    {
        std::size_t pos = second.find_first_of('C');
        int row = std::stoi(second.substr(1, pos - 1));
        int col = std::stoi(second.substr(pos + 1));
        val2 = fields[row - 1][col - 1]->getValue();
    }

    if(formula[pos] == '+')
    {
        return val1 + val2;
    }else if(formula[pos] == '-')
    {
        return val1 - val2;
    }else if(formula[pos] == '*')
    {
        return val1 * val2;
    }else if(formula[pos] == '/')
    {
        return val1 / val2;
    }
    else if(formula[pos] == '^')
    {
        return std::pow(val1, val2);
    }
}

void SpreadSheet::updateSpreadSheet()
{
    for(std::size_t i = 0; i < colWidths.size(); ++i)//for every column
    {
        for(std::size_t j = 0; j < fields.size(); ++j)//go through every element in the column
        {
            if(fields[j][i]->getType() == Type::FORMULA)
            {
                Formula* f = dynamic_cast<Formula*>(fields[j][i]);
                f->setResult(calculateFormula(f->getValueStr()));

            }
            
            if(fields[j][i]->getLength() > colWidths[i])
            {
                colWidths[i] = fields[j][i]->getLength();
            }            
        }
    }
}

//not used
/*void SpreadSheet::addField(int row, int col,const Field* field)
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
//not used
void SpreadSheet::addField()
{
    std::string rowStr, colStr;
    int row = 0, col = 0;
   
    std::cout<<"row: ";
    std::cin>>rowStr;
    std::cout<<"column: ";
    std::cin>>colStr;

    if(!isWholeNumber(rowStr) || !isWholeNumber(colStr))//!!!!!!!!!!!!!!!!!!!!!
    {
        std::cout<<"Invalid input\n";
        return;
    }

    
    row = std::stoi(rowStr);
    col = std::stoi(colStr);

    if(row < rows && col < cols)
    {
        std::cout<<"Field already exists\n";
        std::cout<<"Do you want to edit it? (y/n): ";
        std::string answer;
        std::cin>>answer;

        std::cin.ignore();//

        if(answer == "y")
        {
            editField(row, col);
        }else if(answer == "n")
        {
            return;
        }else
        {
            std::cout<<"Invalid input\n";
            return;
        }
    }


    //we have bigger row or column or both

    if(row > rows)
    {
        fields.resize(row);//resize the rows
        for(std::size_t i = rows; i < fields.size(); ++i)
        {
            fields[i].resize(cols);//resize the columns
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                //if(fields[i][j] == nullptr)
                fields[i][j] = new EmptyField(i + 1, j + 1);//add empty fields
            }
        }
        rows = row;//update the table rows
    }

    if(col > cols)//we are adding a new column
    {
        
        colWidths.resize(col);//resize the columns
        for(std::size_t i = 0; i < fields.size(); ++i)
        {
            fields[i].resize(col);//resize the columns
            for(std::size_t j = cols; j < fields[i].size(); ++j)
            {
                //if(fields[i][j] == nullptr)
                fields[i][j] = new EmptyField(i + 1, j + 1);//add empty fields
            }
        }
        cols = col;//update the table columns
    }

    std::cin.ignore();
    editField(row, col);       
    
}
*/

void SpreadSheet::editField(int row,int col, std::string &value)
{
    int result = whatStringIsThat(value);
    
    switch (result)
    {
        case 0://0 is incorrect
        {    
            std::cerr<<"Error: row "<<row<<", col "<<col<<", "<<value<<" is unknown data type\n";
            break;
        }
        case 1://1 is whole number
        {
            if(value[0] == '+')
            {
                value = value.substr(1);
            }
            Field* f = new WholeNumber(row, col, value);
            fields[row - 1][col - 1] = f;
            break;
        }
        case 2://2 is decimal number
        {
            if(value[0] == '+')
            {
                value = value.substr(1);
            }
            if(value[0] == '.')
            {
                value = "0" + value;
            }
            if(value[value.size()-1] == '.')
            {
                value = value + "0";
            }
            Field* f = new DecimalNumberField(row, col, value);
            fields[row - 1][col - 1] = f;
            break;
        }
        case 3://3 is string
        {
            Field* f = new String(row, col, value);
            fields[row - 1][col - 1] = f;
            break;
        }
        case 4://4 is formula
        {
            //check if there is / followed by adress whose value is 0
            if(value.find("/0") != std::string::npos)//there is devision by 0
            {
                std::cerr<<"Error: row "<<row<<", col "<<col<<", "<<value<<" is division by 0\n";
                Field* f = new String(row, col, "\"ERROR\"");
                fields[row - 1][col - 1] = f;
            }
            else
            {
                Field* f = new Formula(row, col, value,calculateFormula(value));
                fields[row - 1][col - 1] = f;
            }
            
            break;
        }
        case 5://5 is empty
        {
            Field* f = new EmptyField(row, col);
            fields[row - 1][col - 1] = f;
            break;
        }
    }

    updateSpreadSheet();
}

void SpreadSheet::editField(int row, int col)
{
    std::cout<<"new value: ";
    std::string newValue;
    getline(std::cin, newValue);

    editField(row, col, newValue);
}

void SpreadSheet::editField()
{
    std::string rowStr, colStr;
    int row = 0, col = 0;
    do{
        std::cout<<"row: ";
        std::cin>>rowStr;
        std::cout<<"column: ";
        std::cin>>colStr;
        if(!isWholeNumber(rowStr) || !isWholeNumber(colStr))
        {
            std::cout<<"Invalid input\n";
            return;
        }

        row = std::stoi(rowStr);
        col = std::stoi(colStr);
        if(row > rows || col > cols)
        std::cout<<"Invalid row or column\n";
    }while(row > rows || col > cols);    

    std::cout<<"new value: ";
    std::string newValue;
    std::cin.ignore();
    getline(std::cin, newValue);

    editField(row, col, newValue);
}

void SpreadSheet::print() const
{
    if(cols == 0 && rows == 0)
    {
        std::cout<<"Empty table\n";
        return;
    }
    std::cout<<"\nRows: "<<fields.size()<<" Cols: "<<fields[0].size()<<"\n";
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
            std::cout<<fields[i][j]->print();
        }
        std::cout<<'|'<<std::endl;
    }
}

void SpreadSheet::saveToFile(const std::string &fileName) const
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
        std::cout<<"Saved to "<<fileName<<"\n";
    }
    else
    {
        std::cerr<<"Could not open the file\n";
    }
}

void SpreadSheet::saveToFile() const
{
    if(fileN == "")
    {
        std::cerr<<"Error: no file name\n";
    }
    else
    {
        saveToFile(fileN);
    }
}

void SpreadSheet::loadFromFile(const std::string &fileName)
{
    std::ifstream file(fileName);
    if(file.is_open())
    {
        std::string line,element;
        int comaCount = 0;
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
                std::getline(file, element, ',');

                int resultType = whatStringIsThat(element);                

                if(resultType == 0 && comaCount != cols)
                {
                    std::cerr << "Error: File corrupted at row " << i + 1 << ". Expected " << cols << " commas, found " << comaCount << std::endl;
                    assert(false && "Error: File corrupted");
                }
                comaCount++;

                if (!file.eof() && file.peek() == '\n') // Check if the next character is a newline
                {                    
                    file.ignore(1); // Ignore the newline character
                }

                switch (resultType)
                {
                    case 0://0 is incorrect
                    {    
                        std::cerr<<"Error: row "<<i + 1<<", col "<<j + 1<<", " <<element<< " is unknown data type\n";
                        assert(false);
                        break;
                    }
                    case 1://1 is whole number
                    {
                        Field* f = new WholeNumber(i + 1, j + 1, element);
                        fields[i][j] = f;
                        break;
                    }
                    case 2://2 is decimal number
                    {
                        if(line[0] == '+')
                        {
                            line = line.substr(1);
                        }
                        if(line[0] == '.')
                        {
                            line = "0" + line;
                        }
                        if(line[line.size()-1] == '.')
                        {
                            line = line + "0";
                        }
                        Field* f = new DecimalNumberField(i + 1, j + 1, element);//not yet implemented
                        fields[i][j] = f;
                        break;
                    }
                    case 3://3 is string
                    {
                        Field* f = new String(i + 1, j + 1, element);//not yet implemented
                        fields[i][j] = f;
                        break;
                    }
                    case 4://4 is formula
                    {
                        Field* f = new Formula(i + 1, j + 1, element,0);//not yet implemented
                        fields[i][j] = f;
                        break;
                    }
                    case 5://5 is empty
                    {
                        Field* f = new EmptyField(i + 1, j + 1);
                        fields[i][j] = f;
                        break;
                    }
                }
            }
            comaCount = 0;
        }

        fileN = fileName;
    }
    else
    {
        std::cerr<<"Could not open the file\n";
    }

    file.close();

    updateSpreadSheet();
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

void SpreadSheet::resize()
{
    std::size_t newRow,newCol;

    std::cout<<"new rows: ";
    std::cin>>newRow;
    std::cout<<"new columns: ";
    std::cin>>newCol;

    if(newRow < rows)
    {
        std::cout<<"Warning: new rows are less than the current ones\nContinue? (y/n): ";
        char answer;
        std::cin>>answer;
        if(answer == 'n')
        {
            return;
        }else if(answer == 'y')
        {
            fields.resize(newRow);
        }else
        {
            std::cout<<"Invalid input\n";
            return;
        }        
    }

    if(newRow > rows)
    {
        fields.resize(newRow);
        for(std::size_t i = rows; i < newRow; ++i)
        {
            fields[i].resize(cols);
            for(std::size_t j = 0; j < fields[i].size(); ++j)
            {
                fields[i][j] = new EmptyField(i + 1, j + 1);
            }
        }
        
    }

    rows = newRow;

    if(newCol < cols)
    {
        std::cout<<"Warning: new columns are less than the current ones\nContinue? (y/n): ";
        char answer;
        std::cin>>answer;
        if(answer == 'n')
        {
            return;
        }else if(answer == 'y')
        {
            for(std::size_t i = 0; i < fields.size(); ++i)
            {
                fields[i].resize(newCol);
            }
        }else
        {
            std::cout<<"Invalid input\n";
            return;
        }        
    }

    if(newCol > cols)
    {
        colWidths.resize(newCol);
        for(std::size_t i = 0; i < rows; ++i)
        {
            fields[i].resize(newCol);
            for(std::size_t j = cols; j < newCol; ++j)
            {
                fields[i][j] = new EmptyField(i + 1, j + 1);
            }
        }
    }

    cols = newCol;
    std::cin.ignore();
}
