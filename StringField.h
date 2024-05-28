#include <string>
#include "Field.h"

class StringField : public Field
{
public:
    StringField(int row, int column, std::string value);
    
    int getValue() const;
};