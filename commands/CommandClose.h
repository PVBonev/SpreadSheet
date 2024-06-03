#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandClose
 * @brief A class representing a close command in a spreadsheet application.
 * @details This class inherits from the Command class.
 */
class CommandClose : public Command
{
public:
    
    /**
     * @brief Executes the close command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     */
    virtual void execute(SpreadSheet &ss) override
    {
        std::cout<<"File closed\n";
        ss.close();
    }
};