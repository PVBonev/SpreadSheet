#include <string>
#include "Field.h"

class WholeNumber : public Field
{
private:
    int intValue;
public:
    //WholeNumber(int row, int column, int value);
    WholeNumber(int row, int column, std::string value);

    void print() const override;

    bool isValid() override;//not implemented for whole number but rather for string and formula
};
