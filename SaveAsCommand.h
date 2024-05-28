#include "Command.h"

class SaveAsCommand : public Command
{
private:
    std::string fileName;
public:
    SaveAsCommand(std::string fileName) : fileName(fileName) {}
    void execute(SpreadSheet &ss) override
    {
        ss.saveToFile(fileName);
    }
};