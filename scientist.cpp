#include "scientist.h"

Scientist::Scientist()
{   // Adds in the scientist parameters as empty

    _name = " ";
    _gender = ' ';
    _birth = 0;
    _death = 0;
    _age = 0;
    // _valid = false;
}
Scientist::Scientist(string name, char gender, int birth, int death) //vantar bool valid aftast
{   // Adds in the scientist parameters

    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
    // _valid = valid;

    if(_death == 0)
    {
        _age = whatYearIsIt() - _birth;
    }
    else
    {
        _age = _death - _birth;
    }
}

Scientist::Scientist(string id, string name, string birth, string death, string picurl, string about, string abouturl)
{   // stores info for scientist info window
    _id = id;
    _name = name;
    _born = birth;
    _died = death;
    _picurl = picurl;
    _about = about;
    _abouturl = abouturl;
}

string Scientist::getName() const
{
    return _name;
}
string Scientist::getGender() const
{
    string gender = " ";
    gender[0] = _gender;
    return gender;
}
int Scientist::getBirth() const
{
    return _birth;
}
int Scientist::getDeath() const
{
    return _death;
}
int Scientist::getAge() const
{
    if(_death == 0)
    {
        return (whatYearIsIt()  - _birth);
    }
    else
    {
        return (_death - _birth);
    }
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
bool operator == (const Scientist& a, const Scientist& b)
{
    return a._name == b._name;
}


string Scientist::getInfoID() const
{
    return _id;
}
string Scientist::getInfoBorn() const
{
    return _born;
}
string Scientist::getInfoDied() const
{
    return _died;
}
string Scientist::getInfoPicurl() const
{
    return _picurl;
}
string Scientist::getInfoAbout() const
{
    return _about;
}
string Scientist::getInfoAbouturl() const
{
    return _abouturl;
}
