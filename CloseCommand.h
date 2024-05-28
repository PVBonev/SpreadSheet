#include "Command.h"

class CloseCommand : public Command
{
public:
    
    virtual void execute(SpreadSheet &ss) override
    {
        ss.close();
    }
};