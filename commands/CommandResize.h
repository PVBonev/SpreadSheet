#pragma once
#include "Command.h"

/**
 * @class CommandResize
 * @brief A class representing a resize command in a spreadsheet application.
 * @details This class inherits from the Command class. The resize command resizes the spreadsheet when executed.
 */
class CommandResize : public Command
{
public:
    /**
     * @brief Executes the resize command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function resizes the spreadsheet.
     */
    void execute(SpreadSheet &ss)
    {
        ss.resize();
    }
};