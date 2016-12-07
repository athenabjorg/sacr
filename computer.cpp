#include "computer.h"

Computer::Computer()
{
    _name = " ";
    _type = " ";
    _yearBuilt = 0;
    _built = 0;
    _valid = 0;
}
Computer::Computer(string name, int yearBuilt, string type, bool built, bool valid)
{
    _name = name;
    _type = type;
    _yearBuilt = yearBuilt;
    _built = built;
    _valid = valid;
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
bool Computer::getValid()
{
    return _valid;
}
