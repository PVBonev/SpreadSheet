#pragma once
#include <iostream>
#include <string>
#include "Command.h"

class PrintCommand: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        ss.updateSpreadSheet();
        ss.updateSpreadSheet();
        ss.print();
    }
    
};