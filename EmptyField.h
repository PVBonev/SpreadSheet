#pragma once
#include "Field.h"

class EmptyField : public Field
{
public:
    EmptyField(int row, int column);

    std::string getValueStr() const;
};

