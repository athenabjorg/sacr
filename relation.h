#ifndef RELATIONS_H
#define RELATIONS_H

#include <string>

using namespace std;

class Relation
{
public:

    Relation();
    Relation(string scientist, string computer);

    string getScientist();

    string getComputer();

private:

    string _scientist;
    string _computer;

};

#endif // RELATIONS_H
