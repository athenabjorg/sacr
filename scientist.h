#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender, int birthYear, int deathYear);

    string getName() const
    {
        return _name;
    }

    char getGender() const
    {
        return _gender;
    }

    int getBirthYear() const
    {
        return _birthYear;
    }

    int getDeathYear() const
    {
        return _deathYear;
    }

private:

    string _name;
    char _gender;
    int    _birthYear;
    int _deathYear;
};

#endif // SCIENTIST_H
