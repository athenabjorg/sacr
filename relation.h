#ifndef RELATIONS_H
#define RELATIONS_H

#include <string>

using namespace std;

class Relation
{
public:

    Relation();
    Relation(string scientist, string computer, int year);

    string getScientist();

    string getComputer();

    int getYear();

private:

    string _scientist;
    string _computer;
    int _year;

};

#endif // RELATIONS_H
