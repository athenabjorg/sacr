#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(string name, int yearBuilt, string type, bool built, bool valid);
    string getName();
    int getYearBuilt();
    string getType();
    bool getBuilt();
    bool getValid();


private:
    string _name;
    string _type;
    int _yearBuilt;
    bool _built;
    bool _valid;

};

#endif // COMPUTER_H
