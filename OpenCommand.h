#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Command.h"
#include "SpreadSheet.cpp"

class OpenCommand: public Command
{
private:
    std::string fileName;
public:
    OpenCommand(std::string fileName): fileName(fileName) {}

    void execute() override
    {
        std::cout << "Open command  with filename "<<fileName<<"executed\n";
        std::fstream file;
        file.open(fileName, std::ios::in);
        if(!file.is_open())
        {
            std::cout << "File not found\n";
        }
        else
        {
            std::cout << "File opened\n";
        }
    }
};