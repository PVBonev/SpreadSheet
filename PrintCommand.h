#pragma once
#include <iostream>
#include <string>
#include "Command.h"

class PrintCommand: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        std::cout << "Print command called\n";
        ss.print();
    }
    
};