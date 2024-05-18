#include <iostream>
#include "Command.cpp"

class HelpCommand: public Command
{
public:
    void execute() override
    {
        std::cout << "List of commands:\n"
                <<"open <file> - opens a file\n"
                <<"close - closes the currently open file\n"
                <<"save - saves the currently open file\n"
                <<"saveas <file> - saves the currently open file in <file>\n"
                <<"help - prints this information\n"
                <<"exit - exits the program\n";
    }
};