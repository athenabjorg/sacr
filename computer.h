#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int yearBuilt, string type, bool built);
    string getName();
    int getYearBuilt();
    string getType();
    bool getBuilt();


private:
    string _name;
    string _type;
    int _yearBuilt;
    bool _built;

};

#endif // COMPUTER_H
