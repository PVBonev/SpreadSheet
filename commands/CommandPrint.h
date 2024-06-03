#pragma once
#include <iostream>
#include <string>
#include "Command.h"

/**
 * @class CommandPrint
 * @brief A class representing a print command in a spreadsheet application.
 * @details This class inherits from the Command class. The print command updates and prints the spreadsheet when executed.
 */
class CommandPrint: public Command
{
public:
    /**
     * @brief Executes the print command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function updates the spreadsheet twice and then prints it.
     */
    void execute(SpreadSheet &ss) override
    {
        ss.updateSpreadSheet();
        ss.updateSpreadSheet();
        ss.print();
    }
};
