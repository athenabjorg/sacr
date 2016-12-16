#include <ctime>
#include "computer.h"

Computer::Computer()                    // Constructor
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
                                        // Constuctor with parameters
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

string Computer::getID() const          // Returns ID from Computer Class
{
    return _id;
}
string Computer::getName() const        // Returns Name from Computer Class
{
    return _name;
}
string Computer::getYear() const        // Returns Year built from Computer Class
{
    return _year;
}
string Computer::getType() const        // Returns Type of computer from Computer Class
{
    return _type;
}
string Computer::getBuilt() const       // Returns if built or not from Computer Class
{
    return _built;
}
string Computer::getPicurl() const      // Returns picture URL from Computer Class
{
    return _picurl;
}
string Computer::getAbout() const       // Returns about infromation from Computer Class
{
    return _about;
}
string Computer::getAbouturl() const    // Returns about URL from Computer Class
{
    return _abouturl;
}
