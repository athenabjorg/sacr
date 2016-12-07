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
    int     getYearBuilt() const;
    bool    getBuilt() const;


private:
    string _name;
    string _type;
    int _yearBuilt;
    bool _built;

};

#endif // COMPUTER_H
