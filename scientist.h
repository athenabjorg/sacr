#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <ctime>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender, int birth, int death); //vantar bool valid aftast?

    string getName()      const;
    char   getGender()    const;
    int    getBirth()     const;
    int    getDeath()     const;
    int    getAge()       const;

    friend bool operator == (const Scientist& a, const Scientist& b);

private:

    string _name;
    char   _gender;
    int    _birth;
    int    _death;
    int    _age;

    int    whatYearIsIt() const;
        // Returns the current year.
};

#endif // SCIENTIST_H
