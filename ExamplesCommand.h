#pragma once
#include <iostream>
#include "Command.h"

class ExamplesCommand: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        std::cout << "Examples of fields:\n"
                <<"Formulas: =2+3\n"
                <<"=R1C1/2\n"
                <<"=3*R1C1\n"
                <<"=R1C1+R2C2\n"
                <<"Decimal Number: 123.45\n"
                <<"String: \"Hello\"\n";
    }
};