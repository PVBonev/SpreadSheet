#include <iostream>
#include <string>
#include "Command.cpp"
#include "HelpCommand.cpp"
#include "OpenCommand.cpp"

void engine()
{
    std::string input;
    std::cout<<"Enter a command:";
    getline(std::cin, input);
    std::string cmd;
    std::string args;
    bool inCmd = true;
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

    std::cout <<"Entered Command:"<< cmd << std::endl;
    std::cout <<"Entered Arguments:"<< args << std::endl;

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
    else if(cmd.compare("plus") == 0)
    {
        //command = new Plus(args);
         
        std::string firstnum = args.substr(0,1);
        std::string secondnum = args.substr(1,2);
        int num1 = std::stoi(firstnum);
        int num2 = std::stoi(secondnum);
        std::cout<<"Plus: "<<num1 + num2 <<std::endl;
        

    }
    else
    {
        std::cout << "Invalid command\n";
    }

    command->execute();
}

int main()
{
    engine();
    return 0;
}