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

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setGender(char gender)
{
    _gender = gender;
}

void Scientist::setAge(int age)
{
    _age = age;
}

void Scientist::setDeath(int death)
{
    _death = death;
}


bool operator == (const Scientist& a, const Scientist& b)
{
    return a._name == b._name;
}
