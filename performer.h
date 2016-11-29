#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>

using namespace std;

class Performer
{
public:
    Performer();
    Performer(string name, int age);

    string getName() const
    {
        return _name;
    }

    int getAge() const
    {
        return _age;
    }

private:

    string _name;
    int    _age;
};

#endif // PERFORMER_H
