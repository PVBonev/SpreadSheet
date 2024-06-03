#include <iostream>
#include <string>
#include "./commands/Commands.h"

/**
 * @brief The main engine function for the spreadsheet application.
 * 
 * This function handles the main loop of the application, processing user input and executing commands.
 */
void engine()
{
    SpreadSheet sheet; ///< The main spreadsheet object
    std::string cmd; ///< The command entered by the user
    std::string args; ///< The arguments for the command
    bool inCmd = true; ///< Flag to indicate if the input is a command
    bool closed = true; ///< Flag to indicate if the spreadsheet is closed

    std::cout<<"Welcome to Peci's SpreadSheet \n\ntype \"help\" for a list of commands and \"examples\" for example fields\n";
    std::string input; ///< The raw input from the user
    do
    {
        std::cout<<"\n>";
        cmd.clear();
        args.clear();
        inCmd = true;
        getline(std::cin, input);

        // Parse the input into command and arguments
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == ' ')//if we read a space we are done with the command
            {
                inCmd = false;
                continue;
            }
            if(inCmd)//if we read a command we push to cmd
            {
                cmd.push_back(input[i]);
            }
            else// else we push to arguments
            {
                args.push_back(input[i]);
            }
        }

        Command* command; ///< The command object to execute

        // Determine the command to execute based on the input
        if(cmd.compare("help") == 0)//its not the terminating 0//cmd == "help"
        {
            command = new CommandHelp();            
        }
        else if(cmd.compare("open") == 0)
        {
            command = new CommandOpen(args);
            closed = false;
        }
        else if(cmd.compare("close") == 0)
        {
            command = new CommandClose();
            closed = true;
        }
        else if(cmd.compare("save") == 0)
        {
            command = new CommandSave();
        }
        else if(cmd.compare("saveas") == 0)
        {
            command = new CommandSaveAs(args);
        }
        else if(cmd.compare("edit") == 0)
        {
            if(closed)
            {
                std::cout<<"No file is open\n";
                command = new CommandEmpty();
            } else
            {
                command = new CommandEdit(args);
            }
        }
        else if (cmd.compare("resize") == 0) 
        {
          command = new CommandResize();
          closed = false;
        }
        else if(cmd.compare("print") == 0)
        {
            command = new CommandPrint();
        }
        else if(cmd.compare("examples") == 0)
        {
            command = new CommandExamples();
        }
        else if(cmd.compare("exit") == 0)
        {
            std::cout<<"exit command called\n";
            command = new CommandEmpty();
        }
        else
        {   
            command = new CommandInvalid();
        }

        command->execute(sheet); ///< Execute the command
    }while(cmd != "exit");
}