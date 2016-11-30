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

    void setName(string name);
    void setGender(char gender);
    void setAge(int age);
    void setDeath(int death);

    friend bool operator == (const Scientist& a, const Scientist& b);

private:

    string _name;
    char _gender;
    int _age;
    int _death;
};

#endif // SCIENTIST_H
