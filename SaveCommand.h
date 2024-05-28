#include "Command.h"

class SaveCommand : public Command
{
public:
    void execute(SpreadSheet &ss) override
    {
        ss.saveToFile();
    }
};