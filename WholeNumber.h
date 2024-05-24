#include <string>
#include "Field.h"

class WholeNumber : public Field
{

public:
    WholeNumber(int row, int column, std::string value);

    virtual void print() const override;


};
