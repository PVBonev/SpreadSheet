#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandOpen
 * @brief A class representing an open command in a spreadsheet application.
 * @details This class inherits from the Command class. The open command opens a file when executed.
 */
class CommandOpen: public Command
{
    std::string args; ///< The arguments for the open command

public:
    /**
     * @brief Constructor for the CommandOpen class.
     * @param args The arguments for the open command.
     */
    CommandOpen(std::string args) : args(args) {}

    /**
     * @brief Executes the open command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function opens a file if a filename is specified.
     */
    void execute(SpreadSheet &ss) override
    {
        if(args.empty())
        {
            std::cout<<"No file specified\n";
        }else
        {
            std::cout<<"File opened\n";
            ss.loadFromFile(args);
        }
    }
};
