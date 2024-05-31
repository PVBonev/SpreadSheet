#include "Command.h"

class EditCommand : public Command
{
    std::string args;
public:
    EditCommand(std::string args) : args(args) {}
    void execute(SpreadSheet &ss)
    {
        if(args.empty())
        {
            ss.editField();
        }else
        {
            std::size_t pos = args.find_first_of("C");
            std::size_t pos2 = args.find_first_of(":");
            //if pos2 is not found we have args in the form of R1C1 else we have R1C1=2+3

            if(pos2 == std::string::npos)
            {
                int row = std::stoi(args.substr(1, pos - 1));
                int col = std::stoi(args.substr(pos+1));
                ss.editField(row, col);
            }
            else
            {
                int row = std::stoi(args.substr(1, pos - 1));
                int col = std::stoi(args.substr(pos+1, pos2 - pos - 1));
                std::string formula = args.substr(pos2 + 1);
                ss.editField(row, col, formula);
            }
            //int row = std::stoi(args.substr(1, pos - 1));
            //int col = std::stoi(args.substr(pos+1));
            //ss.editField(row, col);
        }
    }
};