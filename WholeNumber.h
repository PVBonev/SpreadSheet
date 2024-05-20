#include <string>
#include "Field.h"

class WholeNumber : public Field
{
private:
    int value;
public:
    WholeNumber(int row, int column, int value);
    WholeNumber(int row, int column, std::string value);

    void setValue(int value);
    void setValue(std::string value);
    int getValue() const;

    bool isValid() override;//not implemented for whole number but rather for string and formula
    void print() const;
};
