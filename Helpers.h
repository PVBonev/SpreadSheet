#pragma once
#include <iostream>
#include <string>

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

            if(isWholeNumber(row) && isWholeNumber(col))
            {
                if(std::stoi(row) > 0 && std::stoi(col) > 0
                  && std::stoi(row) < 10000 && std::stoi(col) < 10000)
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

        // || isDecimalNumber
        if((isWholeNumber(substr1) || isDecimalNumber(substr1) || isAdress2(substr1)) 
        && (isWholeNumber(substr2) || isDecimalNumber(substr2) ||isAdress2(substr2)))
        return true;
    }
  }

  return false;
}

bool isEmpty(std::string str)
{
    if(str == " ")
    {
        return true;
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
    if(isEmpty(str))
    {
        return 5;
    }
    
    return 0;
}


std::string removeZeros(std::string value)// recieve 123.5000000 ->123.5
{
    for(std::size_t i = value.size() - 1; i >= 0; --i)
    {
        if(value[i] == '0')
        {
            value.pop_back();
        }
        else
        {
            break;
        }
    }

    if(value[value.size() - 1] == '.')
    {
        value.pop_back();
    }
    
    return value;
}
