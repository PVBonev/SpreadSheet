#pragma once
#include "SpreadSheet.h"

class Command
{
public:
    virtual void execute(SpreadSheet &ss) =0;
};
