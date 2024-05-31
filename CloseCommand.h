#include "Command.h"

class CloseCommand : public Command
{
public:
    
    virtual void execute(SpreadSheet &ss) override
    {
        std::cout<<"File closed\n";
        ss.close();
    }
};