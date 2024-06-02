#pragma once
#include <iostream>
#include "Command.h"

class InvalidCommand: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        std::cout << "Invalid input\n";
    }
};