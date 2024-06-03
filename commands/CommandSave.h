#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandSave
 * @brief A class representing a save command in a spreadsheet application.
 * @details This class inherits from the Command class. The save command saves the spreadsheet when executed.
 */
class CommandSave: public Command
{
public:
    /**
     * @brief Executes the save command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function saves the spreadsheet.
     */
    void execute(SpreadSheet &ss) override
    {
        ss.saveToFile();
    }
};
