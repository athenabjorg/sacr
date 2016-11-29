#include "scientist.h"

Scientist::Scientist()
{
    _name = " ";
    _gender = ' ';
    _age = 0;
    _death = 0;
}

Scientist::Scientist(string name, char gender, int age, int death)
{
    _name = name;
    _gender = gender;
    _age = age;
    _death = death;
}

string Scientist::getName() const
{
    return _name;
}

char Scientist::getGender() const
{
    return _gender;
}

int Scientist::getAge() const
{
    return _age;
}

int Scientist::getDeath() const
{
    return _death;
}
