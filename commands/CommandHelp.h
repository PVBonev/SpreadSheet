#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandHelp
 * @brief A class representing a help command in a spreadsheet application.
 * @details This class inherits from the Command class. The help command prints a list of available commands when executed.
 */
class CommandHelp: public Command
{
public:
    /**
     * @brief Executes the help command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function prints a list of available commands.
     */
    void execute(SpreadSheet &ss) override
    {
        std::cout << "List of commands:\n"
                <<"open <file> - opens a file\n"
                <<"close - closes the currently open file\n"
                <<"save - saves the currently open file\n"
                <<"saveas <file> - saves the currently open file in <file>\n"
                <<"edit or edit <adress> or edit <adress>: <content> - edits the content of a cell\n"
                <<"resize - resizes the table\n"
                <<"print - prints the table\n"
                <<"help - prints this information\n"
                <<"examples - prints examples of fields\n"
                <<"exit - exits the program\n";
    }
};
