#pragma once
#include "Command.h"

class EmptyCommand: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
    }
};