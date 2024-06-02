#pragma once
#include "Command.h"

class CommandResize : public Command
{
public:
    void execute(SpreadSheet &ss)
    {
        ss.resize();
    }
};