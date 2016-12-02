#include "scientist.h"

Scientist::Scientist()
{
    _name = " ";
    _gender = ' ';
    _birth = 0;
    _death = 0;
    _age = 0;
}
Scientist::Scientist(string name, char gender, int birth, int death, int age)
{
    _name = name;
    _gender = gender;
    _birth = birth;
    _death = death;
    _age = age;
}
string Scientist::getName() const
{
    return _name;
}
char   Scientist::getGender() const
{
    return _gender;
}
int    Scientist::getBirth() const
{
    return _birth;
}
int    Scientist::getDeath() const
{
    return _death;
}
int    Scientist::getAge() const
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
void   Scientist::setName(string name)
{
    _name = name;
}
void   Scientist::setGender(char gender)
{
    _gender = gender;
}
void   Scientist::setBirth(int birth)
{
    _birth = birth;
}
void   Scientist::setDeath(int death)
{
    _death = death;
}
void   Scientist::setAge(int age)
{
    _age = age;
}
bool   operator == (const Scientist& a, const Scientist& b)
{
    return a._name == b._name;
}
int Scientist::whatYearIsIt() const // Returns the current year.
{
    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
