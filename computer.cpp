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
string Computer::getName()
{
    return _name;
}
int Computer::getYearBuilt()
{
    return _yearBuilt;
}
string Computer::getType()
{
    return _type;
}
bool Computer::getBuilt()
{
    return _built;
}
