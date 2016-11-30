#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender, int birth, int death, int age);

    string getName()   const;
    char   getGender() const;
    int    getBirth()  const;
    int    getDeath()  const;
    int    getAge()    const;

    void setName   (string name);
    void setGender (char gender);
    void setBirth  (int birth);
    void setDeath  (int death);
    void setAge    (int age);

    friend bool operator == (const Scientist& a, const Scientist& b);

private:

    string _name;
    char   _gender;
    int    _birth;
    int    _death;
    int    _age;
};

#endif // SCIENTIST_H
