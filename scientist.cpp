#include "scientist.h"

Scientist::Scientist()                                      // Constructor
{   // Adds in the scientist parameters as empty

    _id = "0";
    _name = "0";
    _gender = "0";
    _born = "0";
    _died = "0";
    _picurl = "0";
    _about = "0";
    _abouturl = "0";
}
                                                            // Constructor with parameters
Scientist::Scientist(string id, string name, string gender, string born, string died, string picurl, string about, string abouturl)
{   // Adds in the scientist parameters

    _id = id;
    _name = name;
    _gender = gender;
    _born = born;
    _died = died;
    _picurl = picurl;
    _about = about;
    _abouturl = abouturl;

    if(_died == "0")
    {
        _age = whatYearIsIt() - stoi(_born);
    }
    else
    {
        _age = stoi(_died) - stoi(_born);
    }
}

string Scientist::getID() const                             // Returns ID from Scientist Class
{
    return _id;
}
string Scientist::getName() const                           // Returns Name from Scientist Class
{
    return _name;
}
string Scientist::getGender() const                         // Returns Gender from Scientist Class
{
    return _gender;
}
string Scientist::getBorn() const                           // Returns Year built from Scientist Class
{
    return _born;
}
string Scientist::getDied() const                           // Returns Year of death from Scientist Class
{
    return _died;
}
string Scientist::getPicurl() const                         // Returns picture URL from Scientist Class
{
    return _picurl;
}
string Scientist::getAbout() const                          // Returns about infromation from Scientist Class
{
    return _about;
}
string Scientist::getAbouturl() const                       // Returns about URL from Scientist Class
{
    return _abouturl;
}
int    Scientist::getAge() const                            // Returns age from Scientist Class
{
    return _age;
}
int    Scientist::whatYearIsIt() const                      // Returns current year
{   // Returns the current year.

    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
bool operator == (const Scientist& a, const Scientist& b)   // Returns true if parameter a == parameter b
{
    return a._name == b._name;
}


