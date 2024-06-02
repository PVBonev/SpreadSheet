#pragma once
#include <iostream>
#include "Command.h"

class CommandHelp: public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        std::cout << "List of commands:\n"
                <<"open <file> - opens a file\n"
                <<"close - closes the currently open file\n"
                <<"save - saves the currently open file\n"
                <<"saveas <file> - saves the currently open file in <file>\n"
                <<"edit or edit <adress> or edit <adress>: <content> - edits the content of a cell\n"
                <<"print - prints the table\n"
                <<"help - prints this information\n"
                <<"examples - prints examples of fields\n"
                <<"exit - exits the program\n";
    }
};