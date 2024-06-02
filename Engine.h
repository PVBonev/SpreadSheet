#include <iostream>
#include <string>
#include "./commands/CommandHelp.h"
#include "./commands/CommandOpen.h"
#include "./commands/CommandClose.h"
#include "./commands/CommandPrint.h"
#include "./commands/CommandInvalid.h"
#include "./commands/CommandEmpty.h"
#include "./commands/CommandSaveAs.h"
#include "./commands/CommandSave.h"
#include "./commands/CommandEdit.h"
#include "./commands/CommandExamples.h"
#include "./commands/CommandResize.h"


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

        command->execute(sheet);
    }while(cmd != "exit");
}

