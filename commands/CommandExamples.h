#pragma once
#include <iostream>
#include "Command.h"

/**
 * @class CommandExamples
 * @brief A class representing an examples command in a spreadsheet application.
 * @details This class inherits from the Command class. The examples command prints examples of fields when executed.
 */
class CommandExamples: public Command
{
public:
    /**
     * @brief Executes the examples command on a given spreadsheet.
     * @param ss The spreadsheet to execute the command on.
     * @note This function prints examples of fields.
     */
    void execute(SpreadSheet &ss) override
    {
        std::cout << "Examples of fields:\n"
                <<"Formulas:\n =2+3\n"
                <<" =R1C1/2\n"
                <<" =3*R1C1\n"
                <<" =R1C1+R2C2\n"
                <<"\nDecimal Number:\n 123.45\n"
                <<"\nString: \n \"Hello\"\n";
    }
};