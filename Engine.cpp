#include <iostream>
#include <string>
#include "HelpCommand.h"
#include "OpenCommand.h"
#include "CloseCommand.h"
#include "PrintCommand.h"
#include "EmptyCommand.h"


void engine()
{
    SpreadSheet sheet;
    std::string cmd;
    std::string args;
    bool inCmd = true;

    std::string input;
    do
    {
        std::cout<<"\nEnter a command:";
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

        //cmd.push_back('\0');
        Command* command;

        std::cout<<"cmd: "<<cmd<<std::endl;
        std::cout<<"args: "<<args<<std::endl;

        if(cmd.compare("help") == 0)//its not the terminating 0//cmd == "help"
        {
            std::cout<<"help command called\n";
            command = new HelpCommand();
            
        }
        else if(cmd.compare("open") == 0)
        {
            std::cout<<"open command called\n";
            command = new OpenCommand(args);
        }
        else if(cmd.compare("close") == 0)
        {
            std::cout<<"close command called\n";
            command = new CloseCommand();
        }
        else if(cmd.compare("print") == 0)
        {
            std::cout<<"print command called\n";
            command = new PrintCommand();
        }
        else if(cmd.compare("exit") == 0)
        {
            std::cout<<"exit command called\n";
        }
        else
        {   
            command = new EmptyCommand();
        }

        command->execute(sheet);
    }while(cmd != "exit");
}

int main()
{
    engine();
    return 0;
}