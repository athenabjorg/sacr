#include "scientist.h"

Scientist::Scientist()
{   // Adds in the scientist parameters as empty

    _name = " ";
    _gender = ' ';
    _birth = 0;
    _death = 0;
    _age = 0;
}
Scientist::Scientist(string name, char gender, int birth, int death, int age)
{   // Adds in the scientist parameters

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
int Scientist::whatYearIsIt() const // Returns the current year.
{
    time_t     currentTime;
    struct tm* timeinfo;

    time(&currentTime);
    timeinfo = localtime(&currentTime);

    int currentYear = (timeinfo->tm_year + 1900);
    return currentYear;
}
bool   operator == (const Scientist& a, const Scientist& b)
{
    return a._name == b._name;
}
