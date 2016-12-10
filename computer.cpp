#include <ctime>
#include "computer.h"

Computer::Computer()
{
    _name = " ";
    _type = " ";
    _year = 0;
    _built = 0;
    _yearsSinceBuilt = 0;
}
Computer::Computer(string name, int year, string type, bool built)
{
    _name = name;
    _type = type;
    _year = year;
    _built = built;
    _yearsSinceBuilt = whatYearIsIt() - _year;
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
int Computer::whatYearIsIt() const // Óþarfi ef við ætlum ekki að hafa yearsSinceBuilt
{   // Returns the current year.

    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
int Computer::getYearsSinceBuilt() const
{
    return _yearsSinceBuilt;
}

