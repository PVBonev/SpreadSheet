#include <iostream>
#include <string>
#include "HelpCommand.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "PrintCommand.h"
#include "InvalidCommand.h"
#include "EmptyCommand.h"
#include "SaveAsCommand.h"
#include "SaveCommand.h"
#include "EditCommand.h"
#include "AddFieldCommand.h"
#include "ExamplesCommand.h"


void engine()
{
    SpreadSheet sheet;
    std::string cmd;
    std::string args;
    bool inCmd = true;
    bool closed = true;

    std::cout<<"Welcome to Peci's SpreadSheet \n\ntype \"help\" for a list of commands and \"examples\" for example fields\n";
    std::string input;
    do
    {
        std::cout<<"\n>";
        cmd.clear();
        args.clear();
        inCmd = true;
        getline(std::cin, input);

        
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

        Command* command;

        if(cmd.compare("help") == 0)//its not the terminating 0//cmd == "help"
        {
            command = new HelpCommand();            
        }
        else if(cmd.compare("open") == 0)
        {
            command = new OpenCommand(args);
            closed = false;
        }
        else if(cmd.compare("close") == 0)
        {
            command = new CloseCommand();
            closed = true;
        }
        else if(cmd.compare("save") == 0)
        {
            command = new SaveCommand();
        }
        else if(cmd.compare("saveas") == 0)
        {
            command = new SaveAsCommand(args);
        }
        else if(cmd.compare("edit") == 0)
        {
            if(closed)
            {
                std::cout<<"No file is open\n";
                command = new EmptyCommand();
            } else
            {
                command = new EditCommand(args);
            }
        }
        else if(cmd.compare("add") == 0)
        {
            command = new AddFieldCommand();
        }
        else if(cmd.compare("print") == 0)
        {
            command = new PrintCommand();
        }
        else if(cmd.compare("examples") == 0)
        {
            command = new ExamplesCommand();
        }
        else if(cmd.compare("exit") == 0)
        {
            std::cout<<"exit command called\n";
        }
        else
        {   
            command = new InvalidCommand();
        }

        command->execute(sheet);
    }while(cmd != "exit");
}

int main()
{
    engine();
    return 0;
}

//when spreadsheet is closed do not allow editing