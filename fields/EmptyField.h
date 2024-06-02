#pragma once
#include "Field.h"

class EmptyField : public Field
{
public:
    EmptyField(int row, int column);

    Type getType() const override;

    Field* clone() const override;
};

EmptyField::EmptyField(int row, int column)
    : Field(row, column, " ", Type::Empty) {}

Type EmptyField::getType() const
{
    return Type::Empty;
}

Field* EmptyField::clone() const
{
    return new EmptyField(*this);
}

