#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Command.h"
//#include "SpreadSheet.h"

class OpenCommand: public Command
{
private:
    std::string fileName;
public:
    OpenCommand(std::string fileName): fileName(fileName) {}

    void execute(SpreadSheet &ss) override
    {
        std::fstream file;
        file.open(fileName, std::ios::in);
        if(!file.is_open())
        {
            std::cout << "File not found\n";
        }
        else
        {           
            std::cout<<fileName<<" opened\n"; 
            ss.loadFromFile(fileName);
        }
    }
};