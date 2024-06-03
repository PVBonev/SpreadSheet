#pragma once
#include "../SpreadSheet.h"

/**
 * @class Command
 * @brief An abstract class representing a command to be executed on a spreadsheet.
 */
class Command
{
public:
    /**
     * @brief Executes the command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     */
    virtual void execute(SpreadSheet &ss) =0;
};