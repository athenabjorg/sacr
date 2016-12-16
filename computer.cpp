#include <ctime>
#include "computer.h"

Computer::Computer()
{
    _id = "0";
    _name = "0";
    _year = "0";
    _type = "0";
    _built = "0";
    _picurl = "0";
    _about = "0";
    _abouturl = "0";
}

Computer::Computer(string id, string name, string year, string type, string built, string picurl, string about, string abouturl)
{
    _id = id;
    _name = name;
    _year = year;
    _type = type;
    _built = built;
    _picurl = picurl;
    _about = about;
    _abouturl = abouturl;
}

string Computer::getID() const
{
    return _id;
}
string Computer::getName() const
{
    return _name;
}
string Computer::getYear() const
{
    return _year;
}
string Computer::getType() const
{
    return _type;
}
string Computer::getBuilt() const
{
    return _built;
}
string Computer::getPicurl() const
{
    return _picurl;
}
string Computer::getAbout() const
{
    return _about;
}
string Computer::getAbouturl() const
{
    return _abouturl;
}
