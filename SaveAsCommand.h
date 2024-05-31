#pragma once
#include <iostream>
#include "Command.h"

class SaveAsCommand : public Command
{
private:
    std::string fileName;
public:
    SaveAsCommand(std::string fileName) : fileName(fileName) {}
    void execute(SpreadSheet &ss) override
    {
        std::cout<<fileName<<" saved\n";
        ss.saveToFile(fileName);
    }
};