#pragma once
#include <iostream>
#include "Command.h"

class CommandClose : public Command
{
public:
    
    virtual void execute(SpreadSheet &ss) override
    {
        std::cout<<"File closed\n";
        ss.close();
    }
};