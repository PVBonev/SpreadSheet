#pragma once
#include "Command.h"

class CommandEmpty: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
    }
};