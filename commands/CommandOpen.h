#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Command.h"
//#include "SpreadSheet.h"

class CommandOpen: public Command
{
private:
    std::string fileName;
public:
    CommandOpen(std::string fileName): fileName(fileName) {}

    void execute(SpreadSheet &ss) override
    {
        std::fstream file;
        file.open(fileName, std::ios::in);
        if(!file.is_open())
        {
            std::cerr << "Error:File not found\n";
        }
        else
        {           
            std::cout<<fileName<<" opened\n"; 
            ss.loadFromFile(fileName);
        }
    }
};