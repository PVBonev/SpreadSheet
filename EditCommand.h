#include "Command.h"

class EditCommand : public Command
{
public:
    void execute(SpreadSheet &ss)
    {
        ss.editField();
    }
};