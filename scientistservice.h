#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <vector>
#include "scientist.h"

using namespace std;

class ScientistService
{
public:
    ScientistService();

    //
    vector<Scientist> getScientist(/* TODO: parameters */);
    void addScientist(string name, char gender, int age, int death); // add scientist in to vector
    void addScientist(string name, char gender, int age); // if there is no death date

private:

    vector<Scientist> _scientists;
};

#endif // SCIENTISTSERVICE_H
