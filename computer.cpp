#include "computer.h"

Computer::Computer()
{
    _name = " ";
    _type = " ";
    _yearBuilt = 0;
    _built = 0;
}
Computer::Computer(string name, int yearBuilt, string type, bool built)
{
    _name = name;
    _type = type;
    _yearBuilt = yearBuilt;
    _built = built;
}
string Computer::getName() const
{
    return _name;
}
int Computer::getYearBuilt() const
{
    return _yearBuilt;
}
string Computer::getType() const
{
    return _type;
}
bool Computer::getBuilt() const
{
    return _built;
}
