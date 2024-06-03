#pragma once
#include "Command.h"

/**
 * @class CommandEmpty
 * @brief A class representing an empty command in a spreadsheet application.
 * @details This class inherits from the Command class. An empty command does nothing when executed.
 */
class CommandEmpty: public Command
{
public:
    /**
     * @brief Executes the empty command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function does nothing as it represents an empty command.
     */
    void execute(SpreadSheet &ss) override
    {
        // Do nothing
    }
};