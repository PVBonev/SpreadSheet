#pragma once
#include "Command.h"

class AddFieldCommand : public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        ss.addField();
    }
};