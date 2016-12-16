#include "scientist.h"

Scientist::Scientist()
{   // Adds in the scientist parameters as empty

    _id = "";
    _name = "";
    _gender = "";
    _born = "";
    _died = "";
    _picurl = "";
    _about = "";
    _abouturl = "";
}
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


string Scientist::getID() const
{
    return _id;
}
string Scientist::getName() const
{
    return _name;
}
string Scientist::getGender() const
{
    return _gender;
}
string Scientist::getBorn() const
{
    return _born;
}
string Scientist::getDied() const
{
    return _died;
}
string Scientist::getPicurl() const
{
    return _picurl;
}
string Scientist::getAbout() const
{
    return _about;
}
string Scientist::getAbouturl() const
{
    return _abouturl;
}
int Scientist::getAge() const
{
    return _age;
}

bool operator == (const Scientist& a, const Scientist& b)
{
    return a._name == b._name;
}

int Scientist::whatYearIsIt() const
{   // Returns the current year.

    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
