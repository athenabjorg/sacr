#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int yearBuilt, string type, bool built);
    string  getName() const;
    string  getType() const;
    int     getYear() const;
    bool    getBuilt() const;
    int     getYearsSinceBuilt() const;


private:
    string _name;
    string _type;
    int _year;
    bool _built;
    int _yearsSinceBuilt;

    int whatYearIsIt() const;

};

#endif // COMPUTER_H
