#include "computer.h"

Computer::Computer()
{
    _name = " ";
    _type = " ";
    _year = 0;
    _built = 0;
}
Computer::Computer(string name, int year, string type, bool built)
{
    _name = name;
    _type = type;
    _year = year;
    _built = built;
}
string Computer::getName() const
{
    return _name;
}
int Computer::getYear() const
{
    return _year;
}
string Computer::getType() const
{
    return _type;
}
bool Computer::getBuilt() const
{
    return _built;
}
