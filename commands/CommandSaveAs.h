#pragma once
#include <iostream>
#include <string>
#include "Command.h"

class CommandSaveAs : public Command
{
private:
    std::string fileName;
public:
    CommandSaveAs(std::string fileName) : fileName(fileName) {}
    void execute(SpreadSheet &ss) override
    {
        std::cout<<fileName<<" saved\n";
        ss.saveToFile(fileName);
    }
};