#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandInvalid
 * @brief A class representing an invalid command in a spreadsheet application.
 * @details This class inherits from the Command class. The invalid command prints an error message when executed.
 */
class CommandInvalid: public Command
{
public:
    /**
     * @brief Executes the invalid command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function prints an error message indicating an invalid command.
     */
    void execute(SpreadSheet &ss) override
    {
        std::cout<<"Invalid command\n";
    }
};
