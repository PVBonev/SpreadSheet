#pragma once
#include <iostream>
#include <string>
#include "Command.h"

/**
 * @class CommandSaveAs
 * @brief A class representing a save as command in a spreadsheet application.
 * @details This class inherits from the Command class. The save as command saves the spreadsheet to a specified file when executed.
 */
class CommandSaveAs : public Command
{
private:
    std::string fileName; ///< The name of the file to save to

public:
    /**
     * @brief Constructor for the CommandSaveAs class.
     * @param fileName The name of the file to save to.
     */
    CommandSaveAs(std::string fileName) : fileName(fileName) {}

    /**
     * @brief Executes the save as command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function saves the spreadsheet to the specified file.
     */
    void execute(SpreadSheet &ss) override
    {
        ss.saveToFile(fileName);
    }
};