#pragma once
#include <iostream>
#include "Command.h"

class CommandSave : public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        std::cout<<"File saved\n";
        ss.saveToFile();
    }
};