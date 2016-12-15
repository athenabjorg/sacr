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

Computer::Computer(string id, string name, string year, string type, string picurl, string about, string abouturl)
{
    _id = id;
    _name = name;
    _yearMade = year;
    _type = type;
    _picurl = picurl;
    _about = about;
    _abouturl = abouturl;
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


string Computer::getInfoID() const
{
    return _id;
}
string Computer::getInfoYear() const
{
    return _yearMade;
}
string Computer::getInfoType() const
{
    return _type;
}
string Computer::getInfoPicurl() const
{
    return _picurl;
}
string Computer::getInfoAbout() const
{
    return _about;
}
string Computer::getInfoAbouturl() const
{
    return _abouturl;
}
