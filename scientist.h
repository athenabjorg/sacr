#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender, int age, int death = 0);

    string getName() const;
    char getGender() const;
    int getAge() const;
    int getDeath() const;

private:

    string _name;
    char _gender;
    int _age;
    int _death;
};

#endif // SCIENTIST_H
