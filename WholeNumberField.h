#pragma once
#include <string>
#include "Field.h"

class WholeNumber : public Field
{
public:
    WholeNumber(int row, int column, std::string value);

    int getValue() const;
};
